#ifndef MORIOR_GAMES_SERVICES_HEROES_CONFIG_PUBLISHER_H
#define MORIOR_GAMES_SERVICES_HEROES_CONFIG_PUBLISHER_H

#include <vector>
#include "../Vendor/Observer/HeroConfigPublishable.h"

class HeroesConfigPublisher: public HeroConfigPublishable
{
public:
    void registerObserver(HeroConfigObservable *) override;
    void removeObserver(HeroConfigObservable *) override;
    void notifyObservers(HeroConfigPayload *) override;

private:
    std::vector<HeroConfigObservable *> observers;
};

#endif
