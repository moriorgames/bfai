#ifndef MORIOR_GAMES_SCENES_BATTLE_SCENE_H
#define MORIOR_GAMES_SCENES_BATTLE_SCENE_H

#include "cocos2d.h"
#include "../View/Battle/BattleView.h"
#include "../Http/Client.h"

class BattleScene: public cocos2d::Layer, public Socket::Delegate
{
public:
    static cocos2d::Scene *createScene(std::string json);
    virtual bool init();
    static void goToMainMenuScene(float delay);

    CREATE_FUNC(BattleScene);

private:
    BattleView *battleView;
    Socket *socket;
    Client *client;

    void connectToSocket(int port);
    virtual void onOpen(Socket *ws);
    virtual void onMessage(Socket *ws, const Socket::Data &data);
    virtual void onClose(Socket *ws);
    virtual void onError(Socket *ws, const Socket::ErrorCode &error);
};

#endif
