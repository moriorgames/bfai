#include "AbstractFrame.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

AbstractFrame::AbstractFrame(Layer *layer)
    : ViewHelper(layer)
{
    fontCreator = new FontCreator;

    initFrame();
    initScrollView();
}

void AbstractFrame::initFrame()
{
    frame = Sprite::create("ui/frame-battle-heroes.png");
    frame->setScale(scale);
    frame->setPosition(centerPosition);

    layer->addChild(frame, Z_ORDER_BACKGROUND);
}

void AbstractFrame::initScrollView()
{
    auto heroes = heroRepo->findAll();
    scrollViewHeight = heroes.size() * SCROLL_VIEW_INNER_HEIGHT;

    scrollView = ui::ScrollView::create();
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setScrollBarWidth(10);
    scrollView->setContentSize(Size(
        frame->getContentSize().width - SCROLL_VIEW_MARGIN,
        frame->getContentSize().height - SCROLL_VIEW_MARGIN
    ));
    scrollView->setInnerContainerSize(Size(
        frame->getContentSize().width - SCROLL_VIEW_MARGIN,
        scrollViewHeight
    ));
    scrollView->setPosition(Point(
        scrollView->getPosition().x + SCROLL_VIEW_MARGIN / 2,
        scrollView->getPosition().y + SCROLL_VIEW_MARGIN / 2
    ));
    scrollView->setBounceEnabled(true);
}

Sprite *AbstractFrame::heroRow(int index, Hero *hero)
{
    float y = -index * SCROLL_VIEW_INNER_HEIGHT + scrollViewHeight - SCROLL_VIEW_MARGIN;

    auto sprite = Sprite::create("img/battle-heroes-row-background.png");
    sprite->setAnchorPoint(Point(0, 1));

    auto portrait = new Sprite;
    portrait->initWithSpriteFrameName("portraits/" + hero->getSlug() + ".png");
    portrait->setAnchorPoint(Point(0, 0));
    portrait->setPosition(Point(SCROLL_VIEW_MARGIN * 2, SCROLL_VIEW_MARGIN * 3));
    sprite->addChild(portrait);

    auto name = fontCreator->titleLabel(hero->getName());
    name->setAnchorPoint(Point(0, 0));
    name->setPosition(220, 170);
    sprite->addChild(name);

    addNumericStat(sprite, "battle_heroes_damage", hero->getDamage(), COL_1, ROW_1);
    addNumericStat(sprite, "battle_heroes_health", hero->getHealth(), COL_1, ROW_2);
    addNumericStat(sprite, "battle_heroes_ranged", hero->getRanged(), COL_2, ROW_1);
    addNumericStat(sprite, "battle_heroes_movement", hero->getMovement(), COL_2, ROW_2);

    auto costSprite = ui::Button::create("ui/cost.png", "", "");
    costSprite->setAnchorPoint(Point(0, 0));
    costSprite->setPosition(Point(760, 140));
    auto costLabel = fontCreator->numberLabel(to_string(hero->getCost()));
    costSprite->setTitleLabel(costLabel);
    sprite->addChild(costSprite);

    sprite->setPositionY(y);

    return sprite;
}

void AbstractFrame::addNumericStat(Sprite *sprite, std::string key, int number, float col, float row)
{
    auto damageLabel = fontCreator->infoLabel(translator->tr(key, number));
    damageLabel->setAnchorPoint(Point(0, 0));
    damageLabel->setPosition(col, row);
    sprite->addChild(damageLabel);
}

ui::Button *AbstractFrame::createInfoButton(std::string key)
{
    auto button = ui::Button::create("ui/battle-hero-button.png", "", "");
    button->setAnchorPoint(Point(0, 0));
    button->setPosition(Point(230, BUTTON_ROW));

    auto label = fontCreator->titleLabel(translator->tr(key));
    button->setTitleLabel(label);

    return button;
}

ui::Button *AbstractFrame::createActionButton(std::string key)
{
    auto button = ui::Button::create("ui/battle-hero-button.png", "", "");
    button->setAnchorPoint(Point(0, 0));
    button->setPosition(Point(500, BUTTON_ROW));

    auto label = fontCreator->titleLabel(translator->tr(key));
    button->setTitleLabel(label);

    return button;
}
