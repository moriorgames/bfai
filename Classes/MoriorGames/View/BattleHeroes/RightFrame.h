#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H

#include "AbstractFrame.h"

class RightFrame: public AbstractFrame
{
public:
    explicit RightFrame(Layer *);

private:
    void addView() override;
    void addHeroesList();
    ui::Button *getInfoButton(Hero *);
    ui::Button *getActionButton(Hero *);
};

#endif
