#ifndef MORIOR_GAMES_VENDOR_DTOS_FITNESS_DTO_H
#define MORIOR_GAMES_VENDOR_DTOS_FITNESS_DTO_H

class FitnessDTO
{
public:
    explicit FitnessDTO() = default;
    void clear();
    double getFitnessMove() const;
    void addFitnessMove(double fitnessMove);
    double getFitnessDamage() const;
    void addFitnessDamage(double fitnessDamage);

private:
    double fitnessMove = 0;
    double fitnessDamage = 0;
};

#endif
