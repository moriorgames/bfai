#ifndef MORIOR_GAMES_VIEW_HEROES_CONFIG_TOP_HUD_H
#define MORIOR_GAMES_VIEW_HEROES_CONFIG_TOP_HUD_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../Services/FontCreator.h"
#include "../../Services/HeroesConfigPublisher.h"
#include "../../Vendor/Observer/HeroConfigObservable.h"

class TopHud: public ViewHelper, public HeroConfigObservable
{
public:
    int const ITEM_X = 900;
    int const ITEM_Y = -70;

    TopHud(Layer *layer, HeroesConfigPublisher *);
    void update(HeroConfigPayload *) override;

private:
    Node *node;
    FontCreator *fontCreator;
    HeroesConfigPublisher *publisher;
    Label *costLabel;

    void addView() override;
    void addResetButton();
};

#endif
