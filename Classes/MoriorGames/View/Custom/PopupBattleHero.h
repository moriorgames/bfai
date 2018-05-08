#ifndef MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H
#define MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../Vendor/Entity/Hero.h"

class PopupBattleHero: public ViewHelper
{
public:
    explicit PopupBattleHero(Layer *, Hero *);

private:
    Hero *hero;
    Node *node;
    Sprite *frame;

    void addView() override;
    void addBackground() const;
    void addFrame() const;
};

#endif
