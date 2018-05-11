#include "PopupBattleHero.h"
#include "../../Vendor/Repository/SkillRepository.h"
#include "../../Vendor/Repository/SkillHeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

PopupBattleHero::PopupBattleHero(Layer *layer, Hero *hero, bool canImprove)
    : AbstractFrame(layer), hero{hero}, canImprove{canImprove}
{
    addView();
}

void PopupBattleHero::addView()
{
    node = new Node;
    node->setScale(scale);
    node->setPosition(centerPosition);

    addBackground();
    addFrame();

    layer->addChild(node, Z_ORDER_POPUP);
}

void PopupBattleHero::addFrame()
{
    initFrame();
    initScrollView();

    auto frame = Sprite::create("ui/frame-battle-heroes.png");
    int index = 0;
    auto sprite = heroRow(index, hero);

    index++;
    for (auto skillHero:skillHeroRepo->findSkillsByHero(hero)) {
        addSkillRow(index, skillHero);
        index++;
    }

    scrollView->addChild(sprite);
    frame->addChild(scrollView);
    node->addChild(frame);
}

void PopupBattleHero::addBackground() const
{
    auto background = ui::Button::create("img/black.png", "", "");
    background->setOpacity(190);
    auto nodeToRemove = node;
    background->addTouchEventListener(
        [&, nodeToRemove](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                nodeToRemove->removeAllChildren();
            }
        });

    node->addChild(background);
}

void PopupBattleHero::addSkillRow(int index, SkillHero *skillHero)
{
    auto skill = skillRepo->findById(skillHero->getSkillId());
    float y = -index * SCROLL_VIEW_INNER_HEIGHT + scrollViewHeight - SCROLL_VIEW_MARGIN;

    auto sprite = Sprite::create("img/battle-heroes-row-background.png");
    sprite->setAnchorPoint(Point(0, 1));

    auto portrait = new Sprite;
    portrait->initWithSpriteFrameName("portraits/" + skill->getSlug() + ".png");
    portrait->setAnchorPoint(Point(0, 0));
    portrait->setPosition(Point(SCROLL_VIEW_MARGIN * 2, SCROLL_VIEW_MARGIN * 3));
    portrait->setScale(1.55);
    sprite->addChild(portrait);

    auto name = fontCreator->titleLabel(skill->getName());
    name->setAnchorPoint(Point(0, 0));
    name->setPosition(220, 170);
    sprite->addChild(name);

    auto description = fontCreator->descriptionText(translator->tr("skill_description_" + skill->getSlug()));
    description->setAnchorPoint(Point(0, 1));
    description->setContentSize(Size(500, 200));
    description->setPosition(Point(COL_1, 160));
    sprite->addChild(description);

    if (canImprove) {
        sprite->addChild(
            getUpgradeButton(skill)
        );
    }

    auto costSprite = ui::Button::create("ui/cost.png", "", "");
    costSprite->setAnchorPoint(Point(0, 0));
    costSprite->setPosition(Point(760, 140));
    auto cost = skillHero->getCost() + skill->getCost();
    auto costLabel = fontCreator->numberLabel(to_string(cost));
    costSprite->setTitleLabel(costLabel);
    sprite->addChild(costSprite);

    sprite->setPositionY(y);

    scrollView->addChild(sprite);
}

ui::Button *PopupBattleHero::getUpgradeButton(Skill *skill)
{
    auto button = createInfoButton("battle_heroes_upgrade");
    button->addTouchEventListener(
        [&, skill](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {

            }
        });

    return button;
}
