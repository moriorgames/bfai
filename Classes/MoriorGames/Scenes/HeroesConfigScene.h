#ifndef MORIOR_GAMES_SCENES_HEROES_CONFIG_SCENE_H
#define MORIOR_GAMES_SCENES_HEROES_CONFIG_SCENE_H

#include "cocos2d.h"

class HeroesConfigScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(HeroesConfigScene);
};

#endif
