#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_ABSTRACT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_ABSTRACT_FRAME_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../Services/FontCreator.h"
#include "../../Vendor/Entity/Hero.h"

class AbstractFrame: public ViewHelper
{
public:
    float const FRAME_X = 500;
    float const SCROLL_VIEW_MARGIN = 8;
    float const SCROLL_VIEW_INNER_HEIGHT = 240;

    float const COL_1 = 220;
    float const COL_2 = 410;
    float const COL_3 = 600;

    float const ROW_1 = 90;
    float const ROW_2 = 40;

    explicit AbstractFrame(Layer *);

protected:
    Sprite *frame;
    float scrollViewHeight = 0;
    ui::ScrollView *scrollView;
    FontCreator *fontCreator;

    Sprite *heroRow(int index, Hero *);

private:
    void initFrame();
    void initScrollView();
    void addNumericStat(Sprite *, std::string text, int number, float col, float row);
};

#endif
