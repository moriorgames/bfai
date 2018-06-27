#include "StaticBushConfig.h"

std::vector<std::pair<short, short>> StaticBushConfig::get()
{
    return {
        {8, 3}, {-8, 3}, {8, -3}, {-8, -3},
        {-4, 3}, {-3, 3}, {-2, 3}, {-1, 3}, {0,  3}, {1,   3}, {2,   3},
        {4, -3}, {3, -3}, {2, -3}, {1, -3}, {0, -3}, {-1, -3}, {-2, -3},
    };
}
