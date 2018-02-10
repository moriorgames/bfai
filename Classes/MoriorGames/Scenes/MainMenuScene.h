#ifndef MORIOR_GAMES_SCENES_MAIN_MENU_SCENE_H
#define MORIOR_GAMES_SCENES_MAIN_MENU_SCENE_H

#include "cocos2d.h"

namespace MoriorGames {

class MainMenuScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(MainMenuScene);
};

}

#endif
