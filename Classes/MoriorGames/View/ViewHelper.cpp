#include "ViewHelper.h"
#include "../Screen/Resolution.h"

using MoriorGames::ViewHelper;

ViewHelper::ViewHelper(Layer *layer)
    : layer{layer}
{
    scale = globalResolution->getScale();
}
