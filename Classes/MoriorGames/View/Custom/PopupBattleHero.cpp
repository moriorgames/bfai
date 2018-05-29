#include "PopupBattleHero.h"
#include "../../Services/SoundPlayer.h"
#include "../../Vendor/Containers/HeroesConfig.h"
#include "../../Vendor/Repository/SkillRepository.h"
#include "../../Vendor/Repository/SkillHeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

PopupBattleHero::PopupBattleHero(Layer *layer, HeroesConfigPublisher *publisher, Hero *hero, bool canImprove)
    : AbstractFrame(layer), publisher{publisher}, hero{hero}, canImprove{canImprove}
{
    publisher->registerObserver(this);
    addView();
    addSkillsList();
    auto frame = Sprite::create("ui/frame-battle-heroes.png");
    frame->setPositionY(-FRAME_Y);
    frame->addChild(scrollView);
    node->addChild(frame);
    layer->addChild(node, Z_ORDER_POPUP);
}

PopupBattleHero::~PopupBattleHero()
{
    publisher->removeObserver(this);
}

void PopupBattleHero::update(HeroConfigPayload *)
{
    scrollView->removeAllChildren();
    addSkillsList();
}

void PopupBattleHero::addView()
{
    node = new Node;
    node->setScale(scale);
    node->setPosition(centerPosition);

    addBackground();
    initFrame();
    initScrollView();
}

void PopupBattleHero::addSkillsList()
{
    int index = 0;
    auto heroWithSkills = getHeroWithSkills(hero);
    auto sprite = heroRow(index, heroWithSkills);

    index++;
    for (auto skillHero:skillHeroRepo->findSkillsByHero(hero)) {
        addSkillRow(index, skillHero);
        index++;
    }

    scrollView->addChild(sprite);
}

void PopupBattleHero::addBackground() const
{
    auto background = ui::Button::create("img/black.png", "", "");
    background->setOpacity(190);
    background->addTouchEventListener(
        [&, this](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                node->removeAllChildren();
                delete this;
            }
        });

    node->addChild(background);
}

void PopupBattleHero::addSkillRow(int index, SkillHero *skillHero)
{
    auto skill = skillRepo->findById(skillHero->getSkillId());
    bool isAbleToImproveSkill = heroesConfig->isAbleToAddSkill(skill, hero);
    float y = -index * SCROLL_VIEW_INNER_HEIGHT + scrollViewHeight - SCROLL_VIEW_MARGIN;

    auto sprite = Sprite::create("img/battle-heroes-row-background.png");
    sprite->setAnchorPoint(Point(0, 1));
    sprite->setCascadeOpacityEnabled(true);

    auto portrait = new Sprite;
    portrait->initWithSpriteFrameName("portraits/" + skill->getSlug() + ".png");
    portrait->setAnchorPoint(Point(0, 0));
    portrait->setPosition(Point(SCROLL_VIEW_MARGIN * 2, SCROLL_VIEW_MARGIN * 3));
    portrait->setScale(1.55);
    sprite->addChild(portrait);

    auto name = fontCreator->titleLabel(translator->tr("skill_name_" + skill->getSlug()));
    name->setAnchorPoint(Point(0, 0));
    name->setPosition(220, 170);
    sprite->addChild(name);

    auto description = fontCreator->descriptionText(translator->tr("skill_description_" + skill->getSlug()));
    description->setAnchorPoint(Point(0, 1));
    description->setContentSize(Size(500, 200));
    description->setPosition(Point(COL_1, 160));
    sprite->addChild(description);

    if (canImprove && isAbleToImproveSkill) {
        sprite->addChild(
            getUpgradeButton(skill, hero)
        );
    }
    if (!isAbleToImproveSkill) {
        sprite->setOpacity(OPACITY_INACTIVE);
    }

    auto costSprite = ui::Button::create("ui/cost.png", "", "");
    costSprite->setAnchorPoint(Point(0, 0));
    costSprite->setPosition(Point(760, 140));
    auto cost = skillHero->getCost();
    auto costLabel = fontCreator->numberLabel(to_string(cost));
    costSprite->setTitleLabel(costLabel);
    sprite->addChild(costSprite);

    sprite->setPositionY(y);

    scrollView->addChild(sprite);
}

ui::Button *PopupBattleHero::getUpgradeButton(Skill *skill, Hero *hero)
{
    auto button = createInfoButton("battle_heroes_upgrade");
    button->addTouchEventListener(
        [&, skill, hero, this](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                publisher->notifyObservers(
                    new HeroConfigPayload(HeroConfigPayload::IMPROVE, hero, skill)
                );
                SoundPlayer::playEffect("sounds/button.mp3");
            }
        });

    return button;
}
