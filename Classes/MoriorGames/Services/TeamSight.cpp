#include "TeamSight.h"

TeamSight::TeamSight(std::string side, std::vector<HeroView *> &heroViews, Grid *grid, GridView *gridView)
    : side{side}, heroViews{heroViews}, grid{grid}, gridView{gridView}
{
}

void TeamSight::update(BattleAction *)
{
    hiddenCoordinates.clear();
    auto pathFinder = new PathFinder(grid);
    for (auto coordinate:grid->getCoordinates()) {
        hiddenCoordinates.push_back(coordinate);
    }

    for (auto heroView:heroViews) {
        auto hero = heroView->getBattleHero();
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

    for (auto heroView:heroViews) {
        auto hero = heroView->getBattleHero();
        if (hero->getSide() != side) {
            heroView->show();
            for (auto hide:hiddenCoordinates) {
                if (hero->getCoordinate()->isEqual(hide)) {
                    heroView->hide();
                    break;
                }
            }
        }
    }
}
