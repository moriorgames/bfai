#include "HeroMoveEventListener.h"

HeroMoveEventListener::HeroMoveEventListener(Layer *layer, BattleContainer *battleContainer
)
    : layer{layer}, battleContainer{battleContainer}
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

        auto activeHero = battleContainer->getBattle()->getActiveHero();
        for (auto heroView:battleContainer->getHeroViews()) {
            if (heroView->getHero() == activeHero) {
                auto coordinate = closestCoordinate(screenTouch);
                heroView->moveTo(coordinate);
                activeHero->setCoordinate(coordinate);
                battleContainer->getGridSystem()->removeTilesByName(GridSystem::MOVE_NAME);
            }
        }
        battleContainer->getBattle()->nextHero();
        battleContainer->buildPathScopeView();
    }

    return true;
}

bool HeroMoveEventListener::isTouchWithinBoundariesOfBattleField(Vec2 screenTouch)
{
    return true;
}

Coordinate *HeroMoveEventListener::closestCoordinate(Vec2 screenTouch)
{
    return battleContainer->getGridSystem()->getClosestCoordinate(screenTouch.x, screenTouch.y);
}
