#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../Services/FontCreator.h"
#include "../../Vendor/Entity/Hero.h"

class LeftFrame: public ViewHelper
{
public:
    float const FRAME_X = 500;
    float const SCROLL_VIEW_MARGIN = 8;
    float const SCROLL_VIEW_INNER_HEIGHT = 240;

    float const ROW_1 = 220;
    float const ROW_2 = 410;
    float const ROW_3 = 600;

    explicit LeftFrame(Layer *);

private:
    float scrollViewHeight = 0;
    FontCreator *fontCreator;
    Sprite *frame;
    ui::ScrollView *scrollView;

    void addView() override;
    void addHeroesList();
    void addRow(int index, Hero *);
    ui::Button *getActionButton(Hero *);
};

#endif
