#ifndef MORIOR_GAMES_SERVICES_HEROES_CONFIG_PROCESSOR_H
#define MORIOR_GAMES_SERVICES_HEROES_CONFIG_PROCESSOR_H

#include "../Vendor/Containers/HeroesConfig.h"
#include "../Vendor/Observer/HeroConfigObservable.h"

class HeroesConfigProcessor: public HeroConfigObservable
{
public:
    void update(HeroConfigPayload *) override;
};

#endif
