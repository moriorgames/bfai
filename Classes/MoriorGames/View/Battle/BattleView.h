#ifndef MORIOR_GAMES_VIEW_BATTLE_BATTLE_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_BATTLE_VIEW_H

#include "../ViewHelper.h"
#include "../../Containers/BattleContainer.h"

class BattleView: public ViewHelper
{
public:
    static const std::string NAME;

public:
    BattleView(Layer *, Socket *);
    Battle *getBattle();
    void processOnlineAction(std::string json);
    void ai();

private:
    Socket *socket;
    BattleContainer *battleContainer;

    void addView() override;
};

#endif
