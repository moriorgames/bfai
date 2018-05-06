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
    name->setPosition(COL_1, 150);
    sprite->addChild(name);

    addNumericStat(sprite, "Damage: ", hero->getDamage(), COL_1, ROW_1);
    addNumericStat(sprite, "Health: ", hero->getHealth(), COL_1, ROW_2);
    addNumericStat(sprite, "Ranged: ", hero->getRanged(), COL_2, ROW_1);
    addNumericStat(sprite, "Movement: ", hero->getMovement(), COL_2, ROW_2);

    auto costSprite = ui::Button::create("ui/cost.png", "", "");
    costSprite->setAnchorPoint(Point(0, 0));
    costSprite->setPosition(Point(760, 140));
    auto costLabel = fontCreator->numberLabel(to_string(hero->getCost()));
    costSprite->setTitleLabel(costLabel);
    sprite->addChild(costSprite);

    sprite->setPositionY(y);

    return sprite;
}

void AbstractFrame::addNumericStat(Sprite *sprite, std::string text, int number, float col, float row)
{
    std::string damageText = text + to_string(number);
    auto damageLabel = fontCreator->infoLabel(damageText);
    damageLabel->setAnchorPoint(Point(0, 0));
    damageLabel->setPosition(col, row);
    sprite->addChild(damageLabel);
}
