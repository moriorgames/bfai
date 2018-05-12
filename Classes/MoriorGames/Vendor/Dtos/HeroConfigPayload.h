#ifndef MORIOR_GAMES_VENDOR_DTOS_HERO_CONFIG_PAYLOAD_H
#define MORIOR_GAMES_VENDOR_DTOS_HERO_CONFIG_PAYLOAD_H

#include <string>
#include "../Entity/Hero.h"

class HeroConfigPayload
{
public:
    static const std::string ADD;
    static const std::string REMOVE;
    static const std::string CLEAR;

public:
    HeroConfigPayload(std::string type, Hero *);
    const std::string &getType() const;
    Hero *getHero() const;

private:
    std::string type = "";
    Hero *hero;
};

#endif
