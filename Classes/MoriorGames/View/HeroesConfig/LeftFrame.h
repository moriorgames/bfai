#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H

#include "AbstractFrame.h"
#include "../../Services/HeroesConfigPublisher.h"
#include "../../Vendor/Observer/HeroConfigObservable.h"

class LeftFrame: public AbstractFrame, public HeroConfigObservable
{
public:
    LeftFrame(Layer *, HeroesConfigPublisher *);
    void update(HeroConfigPayload *) override;

private:
    HeroesConfigPublisher *publisher;

    void addView() override;
    void addHeroesList();
    ui::Button *getUpgradeButton(Hero *);
    ui::Button *getActionButton(Hero *);
};

#endif
