#include "Randomizer.h"
#include <random>

int Randomizer::randomize(int min, int max)
{
    std::random_device randomDevice;
    std::mt19937 seed(randomDevice());
    std::uniform_real_distribution<double> distribution(min, max);

    return (int) distribution(seed);
}
