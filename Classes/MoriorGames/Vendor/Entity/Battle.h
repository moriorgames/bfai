#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_H

#include <string>
#include <vector>
#include <algorithm>
#include "BattleHero.h"

class Battle
{
public:
    const std::string &getToken() const;
    void setToken(const std::string &token);
    const std::string &getUserToken() const;
    void setUserToken(const std::string &userToken);
    void addHero(BattleHero *);
    const std::vector<BattleHero *> &getBattleHeroes() const;
    BattleHero *getActiveBattleHero();
    int getActiveSkill() const;
    void setActiveSkill(int activeSkill);
    void nextHero();
    void addTurn();
    void localWin();
    void visitorWin();
    bool isLocalWinner();
    bool isVisitorWinner();
    bool isOnline();
    void setOnline(bool online);
    void print();

private:
    std::string token = "", userToken = "";
    std::vector<BattleHero *> heroes;
    int activeHero = 0;
    int activeSkill = Skill::MOVE_ID;
    int turn = 0;
    bool localWins = false, visitorWins = false;
    bool _isOnline = false;
};

#endif
