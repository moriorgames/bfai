#include "BattleEventListener.h"

BattleEventListener::BattleEventListener(Layer *layer, BattleContainer *battleContainer)
    : layer{layer}, battleContainer{battleContainer}
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(BattleEventListener::onTouchBegin, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(BattleEventListener::onTouchMove, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(BattleEventListener::onTouchEnd, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
        touchListener, layer
    );
}

bool BattleEventListener::onTouchBegin(Touch *touch, Event *event)
{
    return true;
}

bool BattleEventListener::onTouchMove(Touch *touch, Event *event)
{
    return true;
}

bool BattleEventListener::onTouchEnd(Touch *touch, Event *event)
{
    Vec2 screenTouch = layer->convertTouchToNodeSpace(touch);

    if (isTouchWithinBoundariesOfBattleField(screenTouch)) {

        auto coordinate = closestCoordinate(screenTouch);
        auto battleAction = new BattleAction;
        battleAction->setBattleHeroId(
            battleContainer->getBattle()->getActiveBattleHero()->getBattleHeroId()
        );
        battleAction->setCoordinate(coordinate);
        battleContainer->getEventPublisher()->publish(battleAction);

    }

    return true;
}

bool BattleEventListener::isTouchWithinBoundariesOfBattleField(Vec2 screenTouch)
{
    return true;
}

Coordinate *BattleEventListener::closestCoordinate(Vec2 screenTouch)
{
    auto paths = battleContainer->getPathFinder()->getPathScope();

    return battleContainer->getGridSystem()->getClosestCoordinate(paths, screenTouch.x, screenTouch.y);
}
