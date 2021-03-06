#include "TeamSight.h"

TeamSight::TeamSight(
    std::string side, Battle *battle, Grid *grid, GridView *gridView, std::vector<HeroView *> &heroViews
)
    : side{side}, battle{battle}, grid{grid}, gridView{gridView}, heroViews{heroViews}
{
}

void TeamSight::update(BattleAction *)
{
    hiddenCoordinates.clear();
    auto pathFinder = new PathFinder(grid);
    for (auto coordinate:grid->getCoordinates()) {
        hiddenCoordinates.push_back(coordinate);
    }

    for (auto hero:battle->getBattleHeroes()) {
        if (hero->getSide() == side && !hero->isDead()) {
            auto pathScope = pathFinder->buildPathForSight(hero->getCoordinate(), RANGE);
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

    gridView->showActionTiles();
    for (auto heroView:heroViews) {
        auto hero = heroView->getBattleHero();
        if (hero->getSide() != side && !hero->isDead()) {
            if (hero->isVisible()) {
                heroView->show();
            } else {
                hideHero(heroView);
            }
            for (auto hide:hiddenCoordinates) {
                if (hero->getCoordinate()->isEqual(hide)) {
                    hideHero(heroView);
                    break;
                }
            }
        }
    }
}

void TeamSight::hideHero(HeroView *heroView)
{
    heroView->hide();
    if (battle->getActiveBattleHero()->getBattleHeroId() == heroView->getBattleHero()->getBattleHeroId()) {
        gridView->hideActionTiles();
    }
}
