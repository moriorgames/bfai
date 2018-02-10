#include "ViewHelper.h"

using MoriorGames::ViewHelper;

ViewHelper::ViewHelper(Layer *layer)
    : layer{layer}
{
    scale = globalResolution->getScale();
    position = new Position;
    centerPosition = position->getCenteredPosition();
}
