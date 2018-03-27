#include "BattleContainer.h"

BattleContainer::BattleContainer()
{
}

BattleContainer::~BattleContainer()
{
}

void BattleContainer::addHeroView(HeroView *heroView)
{
    heroViews.push_back(heroView);
}

const std::vector<HeroView *> &BattleContainer::getHeroViews() const
{
    return heroViews;
}
