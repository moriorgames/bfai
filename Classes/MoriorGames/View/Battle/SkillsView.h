#ifndef MORIOR_GAMES_VIEW_BATTLE_SKILLS_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_SKILLS_VIEW_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"

class SkillsView: public ViewHelper
{
public:
    SkillsView(Layer *);

private:
    Node *container;

    void addView() override;
};

#endif
