#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_ACTION_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_ACTION_H

#include <string>
#include "../ValueObjects/Coordinate.h"

class BattleAction
{
public:
    const std::string &getBattleToken() const;
    void setBattleToken(const std::string &battleToken);
    const std::string &getUserToken() const;
    void setUserToken(const std::string &userToken);
    int getId() const;
    void setId(int id);
    int getBattleHeroId() const;
    void setBattleHeroId(int battleHeroId);
    int getSkillId() const;
    void setSkillId(int skillId);
    int getExtra() const;
    void setExtra(int extra);
    Coordinate *getCoordinate() const;
    void setCoordinate(Coordinate *);

    void print();

private:
    std::string battleToken = "", userToken = "";
    int id = 0, battleHeroId = 0, skillId = 0, extra = 0;
    Coordinate *coordinate = nullptr;
};

#endif
