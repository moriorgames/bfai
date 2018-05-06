#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H

#include "AbstractFrame.h"

class LeftFrame: public AbstractFrame
{
public:
    explicit LeftFrame(Layer *);

private:
    void addView() override;
    void addHeroesList();
    ui::Button *getActionButton(Hero *);
};

#endif
