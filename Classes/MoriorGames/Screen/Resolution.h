#ifndef MORIOR_GAMES_SCREEN_RESOLUTION_H
#define MORIOR_GAMES_SCREEN_RESOLUTION_H

#include "cocos2d.h"
USING_NS_CC;

class Resolution
{
public:
    static const float SD_WIDTH;
    static const float SD_HEIGHT;
    static const float SD_SCALE;
    static const float HD_WIDTH;
    static const float HD_HEIGHT;
    static const float HD_SCALE;
    static const float HDR_WIDTH;
    static const float HDR_HEIGHT;
    static const float HDR_SCALE;

public:

    Resolution();

    Rect getDesktopRect();

    struct DesignProperties
    {
        float width;
        float height;

        DesignProperties(float w, float h)
        {
            width = w;
            height = h;
        }
    };

    DesignProperties getDesignProperties();

    Resolution *designPropertiesByScreen(Size screenSize);

    void setScale(float s)
    {
        scale = s;
    }

    float getScale() const
    {
        return scale;
    }

private:

    float scale;

    void setDesignProperties(float w, float h);

    DesignProperties designProperties;
};

extern Resolution *globalResolution;

#endif
