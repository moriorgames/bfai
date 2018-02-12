#ifndef MORIOR_GAMES_SCENES_BATTLE_SCENE_H
#define MORIOR_GAMES_SCENES_BATTLE_SCENE_H

#include "cocos2d.h"

namespace MoriorGames {

class BattleScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(BattleScene);
};

}

#endif
