#include "HeroMoveEventListener.h"

HeroMoveEventListener::HeroMoveEventListener(
    Layer *layer, GridSystem *gridSystem, BattleContainer *battleContainer, Battle *battle
)
    : layer{layer}, gridSystem{gridSystem}, battleContainer{battleContainer}, battle{battle}
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(HeroMoveEventListener::onTouchBegin, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HeroMoveEventListener::onTouchMove, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HeroMoveEventListener::onTouchEnd, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
        touchListener, layer
    );
}

bool HeroMoveEventListener::onTouchBegin(Touch *touch, Event *event)
{
    return true;
}

bool HeroMoveEventListener::onTouchMove(Touch *touch, Event *event)
{
    return true;
}

bool HeroMoveEventListener::onTouchEnd(Touch *touch, Event *event)
{
    Vec2 screenTouch = layer->convertTouchToNodeSpace(touch);

    if (isTouchWithinBoundariesOfBattleField(screenTouch)) {
        for (auto heroView:battleContainer->getHeroViews()) {
            if (heroView->getHero() == battle->getActiveHero()) {
                auto coordinate = closestCoordinate(screenTouch);
                heroView->moveTo(coordinate);
                gridSystem->removeTilesByName(GridSystem::MOVE_NAME);
            }
        }
        battle->nextHero();
    }

    return true;
}

bool HeroMoveEventListener::isTouchWithinBoundariesOfBattleField(Vec2 screenTouch)
{
    return true;
}

Coordinate *HeroMoveEventListener::closestCoordinate(Vec2 screenTouch)
{
    return gridSystem->getClosestCoordinate(screenTouch.x, screenTouch.y);
}
