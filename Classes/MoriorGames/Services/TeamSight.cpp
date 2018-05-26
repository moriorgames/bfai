#include "TeamSight.h"

TeamSight::TeamSight(std::string side, Battle *battle, Grid *grid, GridView *gridView)
    : side{side}, battle{battle}, grid{grid}, gridView{gridView}
{
}

void TeamSight::update(BattleAction *)
{
    auto pathFinder = new PathFinder(grid);
    std::vector<Coordinate *> hiddenCoordinates;
    for (auto coordinate:grid->getCoordinates()) {
        hiddenCoordinates.push_back(coordinate);
    }

    for (auto hero:battle->getBattleHeroes()) {
        if (hero->getSide() == side && !hero->isDead()) {
            auto pathScope = pathFinder->buildPathScope(hero->getCoordinate(), RANGE);
            for (auto path:pathScope) {
                for (int i = 0; i < hiddenCoordinates.size(); ++i) {
                    if (path.coordinate->isEqual(hiddenCoordinates[i])) {
                        hiddenCoordinates.erase(hiddenCoordinates.begin() + i);
                    }
                }
            }
        }
    }
    gridView->drawHiddenArea(hiddenCoordinates);
}
