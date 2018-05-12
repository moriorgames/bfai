#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H

#include "AbstractFrame.h"
#include "../../Services/HeroesConfigPublisher.h"
#include "../../Vendor/Observer/HeroConfigObservable.h"

class RightFrame: public AbstractFrame, public HeroConfigObservable
{
public:
    RightFrame(Layer *, HeroesConfigPublisher *);
    void update(HeroConfigPayload *) override;

private:
    HeroesConfigPublisher *publisher;

    void addView() override;
    void addHeroesList();
    ui::Button *getInfoButton(Hero *);
    ui::Button *getActionButton(Hero *);
};

#endif
