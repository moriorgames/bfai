#ifndef MORIOR_GAMES_SCENES_BATTLE_HEROES_SCENE_H
#define MORIOR_GAMES_SCENES_BATTLE_HEROES_SCENE_H

#include "cocos2d.h"

class BattleHeroesScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(BattleHeroesScene);
};

#endif
