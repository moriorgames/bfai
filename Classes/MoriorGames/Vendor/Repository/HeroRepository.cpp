#include "HeroRepository.h"

void HeroRepository::init(const std::string &json)
{
    auto parser = new HeroParser(json);
    for (auto item:parser->parse()) {
        items.push_back(item);
    }
}

const std::vector<Hero *> &HeroRepository::findAll() const
{
    return items;
}

Hero *HeroRepository::findById(int id)
{
    for (auto item:items) {
        if (item->getId() == id) {
            return item;
        }
    }

    return nullptr;
}
