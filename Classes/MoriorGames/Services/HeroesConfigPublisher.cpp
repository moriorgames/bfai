#include "HeroesConfigPublisher.h"
#include <algorithm>

void HeroesConfigPublisher::registerObserver(HeroConfigObservable *observer)
{
    observers.push_back(observer);
}

void HeroesConfigPublisher::removeObserver(HeroConfigObservable *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void HeroesConfigPublisher::notifyObservers(HeroConfigPayload *payload)
{
    auto count = observers.size();
    for (int i = 0; i < count; ++i) {
        observers[i]->update(payload);
    }
}
