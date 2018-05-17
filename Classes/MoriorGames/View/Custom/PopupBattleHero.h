#ifndef MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H
#define MORIOR_GAMES_VIEW_CUSTOM_POPUP_BATTLE_HERO_H

#include "../HeroesConfig/AbstractFrame.h"
#include "../../Vendor/Entity/SkillHero.h"
#include "../../Services/HeroesConfigPublisher.h"
#include "../../Vendor/Observer/HeroConfigObservable.h"

class PopupBattleHero: public AbstractFrame, public HeroConfigObservable
{
public:
    PopupBattleHero(Layer *, HeroesConfigPublisher *, Hero *, bool canImprove = false);
    ~PopupBattleHero();
    void update(HeroConfigPayload *) override;

private:
    bool canImprove = false;
    Hero *hero;
    HeroesConfigPublisher *publisher;
    Node *node;
    Sprite *frame;

    void addView() override;
    void addBackground() const;
    void addSkillsList();
    void addSkillRow(int index, SkillHero *);
    ui::Button *getUpgradeButton(Skill *, Hero *);
};

#endif
