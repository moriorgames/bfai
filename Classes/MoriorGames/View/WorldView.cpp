#include "WorldView.h"

const std::string WorldView::NAME = "world-node";

WorldView::WorldView(Layer *layer)
    : ViewHelper(layer)
{
    spriteAnimator = new SpriteAnimator;
    addView();
}

void WorldView::addView()
{
    container = new Node;

    addWorld();

    layer->addChild(container, Z_ORDER_WORLD);
}

void WorldView::addWorld()
{
    auto world = Sprite::create("img/world.png");
    world->setScale(scale);
    world->setPosition(centerPosition);
    world->setPositionY(centerPosition.y + WORLD_Y * scale);
    world->setName(NAME);

    auto content = world->getContentSize();

    auto details = new Sprite;
    details->initWithSpriteFrameName(spriteAnimator->getFrameName("nexus"));
    details->setPosition(
        content.width / 2,
        content.height / 2 + DETAIL_Y
    );
    details->runAction(detailAction());
    world->addChild(details);

    container->addChild(world);
}

Action *WorldView::detailAction()
{
    return spriteAnimator->generateAction("nexus", "move", 16, 36);
}
