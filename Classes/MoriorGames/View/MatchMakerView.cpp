#include "MatchMakerView.h"
#include "SplashView.h"
#include "../Scenes/MatchMakerScene.h"
#include "../Services/StringFileReader.h"
#include "../Transformers/HeroesConfig2Json.h"
#include "../Vendor/Entity/User.h"

MatchMakerView::MatchMakerView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void MatchMakerView::addView()
{
    new SplashView(layer);
    loadingView = new LoadingView(layer);
    loadingTitleView = new LoadingTitleView(layer);
    client = new Client;
}

bool MatchMakerView::update()
{
    loadingBarPercentage += 2;
    loadingView->setLoadingBarPercentage(loadingBarPercentage);
    loadingTitleView->setEllipsis(loadingBarPercentage);
//    if (loadingBarPercentage % 8 == 0) {
//        // Perform api battle in some periods
//        client->apiBattle();
//    }

    // Passed some iterations go to offline battle
    if (loadingBarPercentage > 100) {
        battleJson = (new HeroesConfig2Json)->transform(heroesConfig);

        return true;
    }

    return false;
}
