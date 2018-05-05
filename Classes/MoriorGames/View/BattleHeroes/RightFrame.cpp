#include "RightFrame.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Utils/TextUtils.h"

RightFrame::RightFrame(Layer *layer)
    : ViewHelper(layer)
{
    fontCreator = new FontCreator;

    addView();
    addHeroesList();
}

void RightFrame::addView()
{
    frame = Sprite::create("ui/frame-battle-heroes.png");
    frame->setScale(scale);
    frame->setPosition(centerPosition);
    frame->setPositionX(centerPosition.x + FRAME_X * scale);

    layer->addChild(frame, Z_ORDER_BACKGROUND);
}

void RightFrame::addHeroesList()
{
    auto heroes = heroRepo->findAll();
    scrollViewHeight = heroes.size() * SCROLL_VIEW_INNER_HEIGHT;

    scrollView = ui::ScrollView::create();
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setScrollBarWidth(3);
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

    int index = 0;
    for (auto hero:heroes) {
        addRow(index, hero);
        index++;
    }

    frame->addChild(scrollView);
}

void RightFrame::addRow(int index, Hero *hero)
{
    float y = -index * SCROLL_VIEW_INNER_HEIGHT + scrollViewHeight - SCROLL_VIEW_MARGIN;

    auto sprite = Sprite::create("img/battle-heroes-row-background.png");
    sprite->setAnchorPoint(Point(0, 1));

    auto portrait = new Sprite;
    portrait->initWithSpriteFrameName("portraits/" + hero->getSlug() + ".png");
    portrait->setAnchorPoint(Point(0, 0));
    portrait->setPosition(Point(SCROLL_VIEW_MARGIN * 2, SCROLL_VIEW_MARGIN * 2));

    auto name = fontCreator->titleLabel(hero->getName());
    name->setAnchorPoint(Point(0, 0));
    name->setPosition(220, 150);

    std::string damageText = "Damage: " + to_string(hero->getDamage());
    auto damageLabel = fontCreator->infoLabel(damageText);
    damageLabel->setAnchorPoint(Point(0, 0));
    damageLabel->setPosition(230, 100);

    std::string healthText = "Health: " + to_string(hero->getHealth());
    auto healthLabel = fontCreator->infoLabel(healthText);
    healthLabel->setAnchorPoint(Point(0, 0));
    healthLabel->setPosition(230, 60);

    std::string rangedText = "Ranged: " + to_string(hero->getRanged());
    auto rangedLabel = fontCreator->infoLabel(rangedText);
    rangedLabel->setAnchorPoint(Point(0, 0));
    rangedLabel->setPosition(430, 100);

    std::string moveText = "Movement: " + to_string(hero->getMovement());
    auto moveLabel = fontCreator->infoLabel(moveText);
    moveLabel->setAnchorPoint(Point(0, 0));
    moveLabel->setPosition(430, 60);

    sprite->addChild(portrait);
    sprite->addChild(name);
    sprite->addChild(damageLabel);
    sprite->addChild(healthLabel);
    sprite->addChild(rangedLabel);
    sprite->addChild(moveLabel);

    sprite->setPositionY(y);

    scrollView->addChild(sprite);
}
