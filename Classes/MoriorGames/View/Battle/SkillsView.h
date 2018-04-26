#ifndef MORIOR_GAMES_VIEW_BATTLE_SKILLS_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_SKILLS_VIEW_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../EventListeners/BattleEventPublishable.h"
#include "../../Vendor/Entity/Battle.h"
#include "../../Vendor/Observer/BattleObservable.h"
#include "../../View/Battle/GridView.h"

class SkillsView: public ViewHelper, public BattleObservable
{
public:
    SkillsView(Layer *, Battle *, BattleEventPublishable *, GridView *);
    void update(BattleAction *) override;

private:
    Node *container;
    Battle *battle;
    BattleEventPublishable *eventPublisher;
    GridView *gridView;

    void addView() override;
    void removeSkillButtons();
    void addSkillButtons();
};

#endif
