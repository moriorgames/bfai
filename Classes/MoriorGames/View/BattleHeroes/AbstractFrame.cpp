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
    portrait->setPosition(Point(SCROLL_VIEW_MARGIN * 2, SCROLL_VIEW_MARGIN * 2));
    sprite->addChild(portrait);

    auto name = fontCreator->titleLabel(hero->getName());
    name->setAnchorPoint(Point(0, 0));
    name->setPosition(ROW_1, 150);
    sprite->addChild(name);

    std::string damageText = "Damage: " + to_string(hero->getDamage());
    auto damageLabel = fontCreator->infoLabel(damageText);
    damageLabel->setAnchorPoint(Point(0, 0));
    damageLabel->setPosition(ROW_1, 90);
    sprite->addChild(damageLabel);

    std::string healthText = "Health: " + to_string(hero->getHealth());
    auto healthLabel = fontCreator->infoLabel(healthText);
    healthLabel->setAnchorPoint(Point(0, 0));
    healthLabel->setPosition(ROW_1, 40);
    sprite->addChild(healthLabel);

    std::string rangedText = "Ranged: " + to_string(hero->getRanged());
    auto rangedLabel = fontCreator->infoLabel(rangedText);
    rangedLabel->setAnchorPoint(Point(0, 0));
    rangedLabel->setPosition(ROW_2, 90);
    sprite->addChild(rangedLabel);

    std::string moveText = "Movement: " + to_string(hero->getMovement());
    auto moveLabel = fontCreator->infoLabel(moveText);
    moveLabel->setAnchorPoint(Point(0, 0));
    moveLabel->setPosition(ROW_2, 40);
    sprite->addChild(moveLabel);

    auto costSprite = ui::Button::create("ui/cost.png", "", "");
    costSprite->setAnchorPoint(Point(0, 0));
    costSprite->setPosition(Point(760, 140));
    auto costLabel = fontCreator->numberLabel(to_string(hero->getCost()));
    costSprite->setTitleLabel(costLabel);
    sprite->addChild(costSprite);

    sprite->setPositionY(y);

    return sprite;
}
