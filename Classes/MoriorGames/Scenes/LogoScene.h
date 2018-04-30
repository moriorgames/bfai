#ifndef MORIOR_GAMES_SCENES_LOGO_SCENE_H
#define MORIOR_GAMES_SCENES_LOGO_SCENE_H

#include "cocos2d.h"

class LogoScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(LogoScene);

private:
    void goToSplashScene(float delay);
};

#endif
