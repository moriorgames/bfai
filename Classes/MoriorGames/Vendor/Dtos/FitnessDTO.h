#ifndef MORIOR_GAMES_VENDOR_DTOS_FITNESS_DTO_H
#define MORIOR_GAMES_VENDOR_DTOS_FITNESS_DTO_H

class FitnessDTO
{
public:
    explicit FitnessDTO() = default;
    void clear();
    double getFitnessMove() const;
    void setFitnessMove(double fitnessMove);
    double getFitnessDamage() const;
    void setFitnessDamage(double fitnessDamage);

private:
    double fitnessMove = 0;
    double fitnessDamage = 0;
};

#endif
