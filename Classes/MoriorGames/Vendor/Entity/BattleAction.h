#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_ACTION_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_ACTION_H

#include <string>
#include "../ValueObjects/Coordinate.h"

class BattleAction
{
public:
    explicit BattleAction(std::string battleToken, std::string userToken, int battleHeroId, int skillId);
    int getId() const;
    void setId(int id);
    const std::string &getBattleToken() const;
    const std::string &getUserToken() const;
    int getBattleHeroId() const;
    int getSkillId() const;
    void setSkillId(int skillId);
    Coordinate *getCoordinate() const;
    void setCoordinate(Coordinate *);
    int getExtra() const;
    void setExtra(int extra);

    void print();

private:
    std::string battleToken = "", userToken = "";
    int id = 0, battleHeroId = 0, skillId = 0, extra = 0;

    Coordinate *coordinate = nullptr;
};

#endif
