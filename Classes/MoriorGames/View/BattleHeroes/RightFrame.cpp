#include "RightFrame.h"
#include "../../Vendor/Repository/HeroRepository.h"

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

    scrollView = ui::ScrollView::create();
    scrollView->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setScrollBarWidth(3);
    scrollView->setContentSize(Size(
        frame->getContentSize().width - SCROLL_VIEW_MARGIN,
        frame->getContentSize().height - SCROLL_VIEW_MARGIN
    ));
    scrollView->setInnerContainerSize(Size(
        frame->getContentSize().width - SCROLL_VIEW_MARGIN,
        heroes.size() * SCROLL_VIEW_INNER_HEIGHT
    ));
    scrollView->setBackGroundColor(Color3B::BLUE);

    float y = heroes.size() * SCROLL_VIEW_INNER_HEIGHT;
    for (auto hero:heroes) {

        addRow(y, hero);

        y -= SCROLL_VIEW_INNER_HEIGHT;
    }

    frame->addChild(scrollView);
}

void RightFrame::addRow(float y, Hero *hero)
{
    auto label = fontCreator->damageLabel(hero->getName());
    label->setPositionY(y);

    scrollView->addChild(label);
}
