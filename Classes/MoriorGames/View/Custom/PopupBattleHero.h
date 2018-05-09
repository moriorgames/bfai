#ifndef MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H
#define MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H

#include "../BattleHeroes/AbstractFrame.h"

class PopupBattleHero: public AbstractFrame
{
public:
    explicit PopupBattleHero(Layer *, Hero *);

private:
    Hero *hero;
    Node *node;
    Sprite *frame;

    void addView() override;
    void addBackground() const;
    void addFrame();
    void addSkillRow(int index, int skillId);
};

#endif
