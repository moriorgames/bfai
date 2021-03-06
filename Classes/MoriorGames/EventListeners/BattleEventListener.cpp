#include "BattleEventListener.h"
#include "../Vendor/Entity/User.h"

BattleEventListener::BattleEventListener(
    Layer *layer, Battle *battle, BattleEventPublishable *eventPublisher, GridContainer *gridContainer
)
    : layer{layer}, battle{battle}, eventPublisher{eventPublisher}, gridContainer{gridContainer}
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
    auto activeHero = battle->getActiveBattleHero();

    if (activeHero->getUserToken() == playerUser->getToken() && isTouchWithinBoundariesOfBattleField(screenTouch)) {

        auto coordinate = closestCoordinate(screenTouch);

        // @TODO I think we have to change "battle->getUserToken()" to  "activeHero->getUserToken()"
        auto action = new BattleAction(
            battle->getToken(),
            battle->getUserToken(),
            activeHero->getBattleHeroId(),
            battle->getActiveSkill()
        );
        action->setCoordinate(coordinate);
        eventPublisher->publish(action);

    }

    return true;
}

bool BattleEventListener::isTouchWithinBoundariesOfBattleField(Vec2 screenTouch)
{
    auto heightTouch = screenTouch.y / globalResolution->getScale();

    return heightTouch > 200 && heightTouch < 1000;
}

Coordinate *BattleEventListener::closestCoordinate(Vec2 screenTouch)
{
    auto paths = gridContainer->getPathFinder()->getPathScope();

    return gridContainer->getClosestCoordinate()->execute(paths, screenTouch.x, screenTouch.y);
}
