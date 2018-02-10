#ifndef MORIOR_GAMES_SCENES_SPLASH_SCENE_H
#define MORIOR_GAMES_SCENES_SPLASH_SCENE_H

#include "cocos2d.h"

namespace MoriorGames {

class SplashScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(SplashScene);

private:

    void goToMainMenuScene(float delay);
};

}

#endif
