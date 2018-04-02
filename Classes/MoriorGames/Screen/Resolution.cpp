#include "Resolution.h"

const float Resolution::SD_WIDTH = 512;

const float Resolution::SD_HEIGHT = 384;

const float Resolution::SD_SCALE = 0.25;

const float Resolution::HD_WIDTH = 1024;

const float Resolution::HD_HEIGHT = 768;

const float Resolution::HD_SCALE = 0.5;

const float Resolution::HDR_WIDTH = 2048;

const float Resolution::HDR_HEIGHT = 1536;

const float Resolution::HDR_SCALE = 1;

Resolution::Resolution()
    : designProperties(Resolution::SD_WIDTH, Resolution::SD_HEIGHT)
{
    scale = Resolution::SD_SCALE;
}

Rect Resolution::getDesktopRect()
{
    return Rect(0, 0, 768, 432);
}

Resolution::DesignProperties Resolution::getDesignProperties()
{
    return designProperties;
}

void Resolution::setDesignProperties(float w, float h)
{
    designProperties.width = w;
    designProperties.height = h;
}

Resolution *Resolution::designPropertiesByScreen(Size screenSize)
{
    if (screenSize.width >= Resolution::HDR_WIDTH) { // retina iPad
        scale = Resolution::HDR_SCALE;
        setDesignProperties(Resolution::HDR_WIDTH, Resolution::HDR_HEIGHT);
    } else if (screenSize.width >= Resolution::HD_WIDTH) { // non retina iPad
        scale = Resolution::HD_SCALE;
        setDesignProperties(Resolution::HD_WIDTH, Resolution::HD_HEIGHT);
    }

    return this;
}
