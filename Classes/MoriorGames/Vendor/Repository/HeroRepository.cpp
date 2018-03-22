#include "HeroRepository.h"

using MoriorGames::HeroRepository;
using MoriorGames::Hero;

void HeroRepository::init(const std::string &json)
{
    auto parser = new HeroParser(json);
    for (auto hero:parser->parse()) {
        heroes.push_back(hero);
    }
}

Hero *HeroRepository::findById(int id)
{
    for (auto hero:heroes) {
        if (hero->getId() == id) {
            return hero;
        }
    }

    return nullptr;
}
