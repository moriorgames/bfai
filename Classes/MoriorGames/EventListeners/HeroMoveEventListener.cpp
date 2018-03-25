#include "HeroMoveEventListener.h"

using MoriorGames::HeroMoveEventListener;

HeroMoveEventListener::HeroMoveEventListener(Layer *layer, GridSystem *gridSystem, std::vector<HeroView *> heroViews, Battle *battle)
    : layer{layer}, gridSystem{gridSystem}, heroViews{heroViews}, battle{battle}
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
        for (auto heroView:heroViews) {
            if (heroView->getHero()->getBattleHeroId() == battle->getActiveHero()->getBattleHeroId()) {
                auto coordinate = closestCoordinate(screenTouch);
                heroView->moveTo(coordinate);
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
