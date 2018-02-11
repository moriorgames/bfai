#include "SpriteAnimator.h"
#include "../Vendor/Utils/TextUtils.h"

using MoriorGames::SpriteAnimator;

cocos2d::Action *
SpriteAnimator::generateAction(
    std::string entity, float frames, std::string action, int direction, float duration, int module
)
{
    auto cacher = SpriteFrameCache::getInstance();
    float actionDuration;
    if (duration == 0) {
        actionDuration = frames / 20;
    } else {
        actionDuration = duration / 20;
    }

    if (!isAllowedDirection(direction)) {
        direction = 0;
    }

    Vector<SpriteFrame *> framesVector;

    for (int frame = 10; frame < 10 + frames; ++frame) {

        std::string frameName;
        if (module > 0 && frame % module == 1) {
            frameName = getFrameName(entity, "explosive", direction, frame);
        } else {
            frameName = getFrameName(entity, action, direction, frame);
        }
        SpriteFrame *spriteFrame = cacher->getSpriteFrameByName(frameName);
        framesVector.pushBack(spriteFrame);
    }

    auto returnedAction = RepeatForever::create(
        Animate::create(
            Animation::createWithSpriteFrames(framesVector, actionDuration / frames)
        )
    );
    returnedAction->setTag(int(action.length()));

    return returnedAction;
}

std::string SpriteAnimator::getFrameName(std::string entity, std::string action, int direction, int frame)
{
    return entity + "/" + action + "/" + to_string(direction) + "/" + to_string(frame) + ".png";
}

bool SpriteAnimator::isAllowedDirection(int direction)
{
    for (int allowed:allowedDirections) {
        if (direction == allowed) {
            return true;
        }
    }

    return false;
}
