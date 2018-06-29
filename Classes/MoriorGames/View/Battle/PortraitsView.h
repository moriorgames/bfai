#ifndef MORIOR_GAMES_VIEW_BATTLE_PORTRAITS_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_PORTRAITS_VIEW_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../EventListeners/BattleEventPublishable.h"
#include "../../Vendor/Entity/Battle.h"
#include "../../Vendor/Observer/BattleObservable.h"

class PortraitsView: public ViewHelper, public BattleObservable
{
public:
    PortraitsView(Layer *, Battle *);
    void update(BattleAction *) override;

private:
    Node *container;
    Battle *battle;

    void addView() override;
};

#endif
