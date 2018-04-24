#ifndef MORIOR_GAMES_VIEW_BATTLE_SKILLS_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_SKILLS_VIEW_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../EventListeners/BattleEventPublishable.h"
#include "../../Vendor/Entity/BattleHero.h"

class SkillsView: public ViewHelper
{
public:
    SkillsView(Layer *, BattleEventPublishable *);
    void addSkillButtons(BattleHero *);

private:
    Node *container;
    BattleEventPublishable *eventPublisher;
    void addView() override;
};

#endif
