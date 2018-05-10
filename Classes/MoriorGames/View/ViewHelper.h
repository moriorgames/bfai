#ifndef MORIOR_GAMES_VIEW_VIEW_HELPER_H
#define MORIOR_GAMES_VIEW_VIEW_HELPER_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "../Screen/Position.h"
#include "../Services/Translator.h"
#include "../Definitions.h"
USING_NS_CC;

using uiTexture = ui::Widget::TextureResType;

class ViewHelper
{
public:
    explicit ViewHelper(Layer *layer);

protected:
    Layer *layer;
    float scale;
    Position *position;
    Point centerPosition;
    Translator *translator;

private:
    virtual void addView()= 0;
};

#endif
