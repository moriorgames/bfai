#include "FitnessDTO.h"

void FitnessDTO::clear()
{
    fitnessMove = 0;
    fitnessDamage = 0;
}

double FitnessDTO::getFitnessMove() const
{
    return fitnessMove;
}

void FitnessDTO::addFitnessMove(double fitnessMove)
{
    this->fitnessMove += fitnessMove;
}

double FitnessDTO::getFitnessDamage() const
{
    return fitnessDamage;
}

void FitnessDTO::addFitnessDamage(double fitnessDamage)
{
    this->fitnessDamage += fitnessDamage;
}
