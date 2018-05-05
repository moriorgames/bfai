#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../Services/FontCreator.h"
#include "../../Vendor/Entity/Hero.h"

class RightFrame: public ViewHelper
{
public:
    float const FRAME_X = 500;
    float const SCROLL_VIEW_MARGIN = 20;
    float const SCROLL_VIEW_INNER_HEIGHT = 150;

    explicit RightFrame(Layer *);

private:
    FontCreator *fontCreator;
    Sprite *frame;
    ui::ScrollView *scrollView;

    void addView() override;
    void addHeroesList();
    void addRow(float y, Hero *);
};

#endif
