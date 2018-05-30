#ifndef MORIOR_GAMES_SCENES_MATCH_MAKER_SCENE_H
#define MORIOR_GAMES_SCENES_MATCH_MAKER_SCENE_H

#include "cocos2d.h"
#include "../View/LoadingView.h"

class MatchMakerScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(MatchMakerScene);

    void increaseLoadingBar(float delay);

private:
    float loadingBarPercentage = 0.0f;
    LoadingView *loadingView;

    void goToBattleScene();
};

#endif
