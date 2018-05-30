#ifndef MORIOR_GAMES_SCENES_MATCH_MAKER_SCENE_H
#define MORIOR_GAMES_SCENES_MATCH_MAKER_SCENE_H

#include "cocos2d.h"
#include "../View/LoadingView.h"
#include "../View/LoadingTitleView.h"

class MatchMakerScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(MatchMakerScene);

    void increaseLoadingBar(float delay);

private:
    std::string json;
    float loadingBarPercentage = 0.0f;
    LoadingView *loadingView;
    LoadingTitleView *loadingTitleView;

    void goToBattleScene();
};

#endif
