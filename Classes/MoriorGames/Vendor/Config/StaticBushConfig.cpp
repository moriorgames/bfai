#include "StaticBushConfig.h"

std::vector<std::pair<short, short>> StaticBushConfig::get()
{
    return {
        {-8, 3}, {-7, 3}, {-6, 3}, {-5, 3}, {8, -3}, {7, -3}, {6, -3}, {5, -3},
    };
}
