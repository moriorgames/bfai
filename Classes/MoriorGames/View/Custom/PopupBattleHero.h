#ifndef MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H
#define MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H

#include "../BattleHeroes/AbstractFrame.h"
#include "../../Vendor/Entity/SkillHero.h"

class PopupBattleHero: public AbstractFrame
{
public:
    PopupBattleHero(Layer *, Hero *, bool canImprove = false);

private:
    bool canImprove = false;
    Hero *hero;
    Node *node;
    Sprite *frame;

    void addView() override;
    void addBackground() const;
    void addFrame();
    void addSkillRow(int index, SkillHero *);
    ui::Button *getUpgradeButton(Skill *, Hero *);
};

#endif
