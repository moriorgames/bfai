#include "BattleEventListener.h"

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

    if (isTouchWithinBoundariesOfBattleField(screenTouch)) {

        auto coordinate = closestCoordinate(screenTouch);
        auto battleAction = new BattleAction;
        battleAction->setBattleHeroId(
            battle->getActiveBattleHero()->getBattleHeroId()
        );
        battleAction->setSkillId(
            battle->getActiveSkill()
        );
        battleAction->setCoordinate(coordinate);
        eventPublisher->publish(battleAction);

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