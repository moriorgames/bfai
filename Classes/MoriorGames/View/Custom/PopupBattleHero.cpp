#include "PopupBattleHero.h"
#include "../../Vendor/Repository/SkillRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

PopupBattleHero::PopupBattleHero(Layer *layer, Hero *hero)
    : AbstractFrame(layer), hero{hero}
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
    auto sprite = heroRow(0, hero);
    scrollView->addChild(sprite);
    frame->addChild(scrollView);
    node->addChild(frame);

    addSkillRow(1, 5);
    addSkillRow(2, 6);
    addSkillRow(3, 7);
    addSkillRow(4, 8);
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

void PopupBattleHero::addSkillRow(int index, int skillId)
{
    auto skill = skillRepo->findById(skillId);
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

    // @TODO here we have to add the text description of the skill
    // @TODO And we have the upgrade button too

    auto costSprite = ui::Button::create("ui/cost.png", "", "");
    costSprite->setAnchorPoint(Point(0, 0));
    costSprite->setPosition(Point(760, 140));
    auto costLabel = fontCreator->numberLabel(to_string(skill->getCost()));
    costSprite->setTitleLabel(costLabel);
    sprite->addChild(costSprite);

    sprite->setPositionY(y);

    scrollView->addChild(sprite);
}
