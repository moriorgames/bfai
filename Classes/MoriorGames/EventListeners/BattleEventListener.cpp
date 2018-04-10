#include "BattleEventListener.h"
#include "../Transformers/BattleAction2Json.h"

BattleEventListener::BattleEventListener(
    Layer *layer,
    BattleContainer *battleContainer,
    BattleEventPublishable *battleEventPublishable
)
    : layer{layer}, battleContainer{battleContainer}, battleEventPublishable{battleEventPublishable}
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

        auto activeBattleHero = battleContainer->getBattle()->getActiveBattleHero();
        for (auto heroView:battleContainer->getHeroViews()) {
            if (heroView->getHero() == activeBattleHero) {
                auto coordinate = closestCoordinate(screenTouch);

                auto battleAction = new BattleAction;
                battleAction->setBattleHeroId(activeBattleHero->getBattleHeroId());
                battleAction->setCoordinate(coordinate);
                BattleAction2Json::transform(battleAction);

                // @TODO this has to be handled by Battle Processor after receive the Action
                heroView->moveTo(coordinate);
                activeBattleHero->setCoordinate(coordinate);
                battleContainer->getGridSystem()->removeTilesByName(GridSystem::MOVE_NAME);
            }
        }
        // @TODO this has to be handled by Battle Processor after receive the Action
        battleContainer->getBattle()->nextHero();
        battleContainer->buildPathScopeView();
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
