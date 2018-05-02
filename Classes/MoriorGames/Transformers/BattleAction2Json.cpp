#include "BattleAction2Json.h"
#include "../Vendor/Utils/TextUtils.h"

std::string BattleAction2Json::transform(BattleAction *battleAction)
{
    std::string json =
        "{ \"battleToken\":\"" + battleAction->getBattleToken() + "\", "
        "\"userToken\":\"" + battleAction->getUserToken() + "\", "
        "\"battleHeroId\":\"" + to_string(battleAction->getBattleHeroId()) + "\", "
        "\"skillId\":\"" + to_string(battleAction->getSkillId()) + "\", "
        "\"x\":\"" + to_string(battleAction->getCoordinate()->x) + "\", "
        "\"y\":\"" + to_string(battleAction->getCoordinate()->y) + "\" }";

    printf("========= BattleAction2Json: \n"
           " - json %s\n",
           json.c_str()
    );

    return json;
}
