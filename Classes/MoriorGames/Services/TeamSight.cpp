#include "TeamSight.h"

TeamSight::TeamSight(std::string side, Battle *battle, GridView *gridView)
    : side{side}, battle{battle}, gridView{gridView}
{
}

void TeamSight::update(BattleAction *)
{
}
