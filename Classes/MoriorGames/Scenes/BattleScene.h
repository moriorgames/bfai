#ifndef MORIOR_GAMES_SCENES_BATTLE_SCENE_H
#define MORIOR_GAMES_SCENES_BATTLE_SCENE_H

#include "cocos2d.h"
#include "../View/Battle/BattleView.h"

class BattleScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();
    virtual bool init();
    void scheduledEvents(float delay);
    static void goToMainMenuScene(float delay);

    CREATE_FUNC(BattleScene);

private:
    BattleView *battleView;

};

#endif
