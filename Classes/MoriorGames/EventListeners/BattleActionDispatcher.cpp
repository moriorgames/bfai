#include "BattleActionDispatcher.h"
#include "../Vendor/Utils/TextUtils.h"

void BattleActionDispatcher::sendAction(BattleAction *action)
{
    std::string data =
        "{ \"userToken\":\"FakeUserToken\", "
        "\"battleToken\":\"FakeBattleToken\", "
        "\"battleHeroId\":\"" + to_string(action->getBattleHeroId()) + "\", "
        "\"skillId\":\"" + to_string(action->getSkillId()) + "\", "
        "\"x\":\"" + to_string(action->getCoordinate()->x) + "\", "
        "\"y\":\"" + to_string(action->getCoordinate()->y) + "\" }";

    printf("========= BattleActionDispatcher: \n"
           " - data %s\n",
           data.c_str()
    );
}
