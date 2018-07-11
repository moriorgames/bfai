#ifndef MORIOR_GAMES_VENDOR_SERVICES_AI_H
#define MORIOR_GAMES_VENDOR_SERVICES_AI_H

#include <cmath>
#include "../../EventListeners/BattleEventPublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Observer/BattleObservable.h"
#include "../Services/BattleProcessor.h"

class AI: public BattleObservable
{
public:
    const std::string AI_TOKEN = "j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB";

    AI(Battle *, BattleProcessor *, BattleEventPublishable *);
    void update(BattleAction *) override;

private:
    Battle *battle;
    BattleProcessor *battleProcessor;
    BattleEventPublishable *eventPublisher;

    void geneticAlgorithm();
};

#endif
