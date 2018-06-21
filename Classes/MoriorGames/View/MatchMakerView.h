#ifndef MORIOR_GAMES_VIEW_MATCH_MAKER_VIEW_H
#define MORIOR_GAMES_VIEW_MATCH_MAKER_VIEW_H

#include "ViewHelper.h"
#include "LoadingView.h"
#include "LoadingTitleView.h"
#include "../Http/Client.h"

class MatchMakerView: public ViewHelper
{
public:
    explicit MatchMakerView(Layer *layer);
    bool update();
    const std::string &getBattleJson() const
    {
        return battleJson;
    }

private:
    int loadingBarPercentage = 0;
    std::string battleJson = "";
    LoadingView *loadingView;
    LoadingTitleView *loadingTitleView;
    Client *client;

    void addView() override;
};

#endif
