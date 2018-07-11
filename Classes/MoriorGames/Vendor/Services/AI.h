#ifndef MORIOR_GAMES_VENDOR_SERVICES_AI_H
#define MORIOR_GAMES_VENDOR_SERVICES_AI_H

#include <cmath>
#include "../../EventListeners/BattleEventPublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Observer/BattleObservable.h"
#include "../Services/BattleProcessor.h"

struct DNA
{
    int x1 = 0;
    int y1 = 0;
    int skill1 = 0;
    int x2 = 0;
    int y2 = 0;
    int skill2 = 0;
};

class AI: public BattleObservable
{
public:
    const int POPULATION = 100;
    const int MAX_GENERATIONS = 100;

    const std::string AI_TOKEN = "j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB";

    AI(Battle *, BattleProcessor *, BattleEventPublishable *);
    void update(BattleAction *) override;

private:
    Battle *battle;
    BattleProcessor *battleProcessor;
    BattleEventPublishable *eventPublisher;
    std::vector<DNA> dnas;

    void geneticAlgorithm();

    void initialize();

    void mutate(DNA &dna, int mutationRate);
};

#endif
