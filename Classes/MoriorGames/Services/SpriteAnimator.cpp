#include "SpriteAnimator.h"
#include "../Vendor/Utils/TextUtils.h"

Action *SpriteAnimator::generateAction(std::string entity, std::string action, int frames, float duration)
{
    int direction = 0;
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
        auto frameName = getFrameName(entity, action, direction, frame);
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

Action *SpriteAnimator::generateSingleAction(std::string entity, std::string action, int frames, float duration)
{
    int direction = 0;
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
        auto frameName = getFrameName(entity, action, direction, frame);
        SpriteFrame *spriteFrame = cacher->getSpriteFrameByName(frameName);
        framesVector.pushBack(spriteFrame);
    }

    auto returnedAction = Sequence::create(
        Animate::create(
            Animation::createWithSpriteFrames(framesVector, actionDuration / frames)
        ), nullptr
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
