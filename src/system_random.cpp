#include <random>
#include <ctime>

int Random(int min, int max)
{
    static std::mt19937 engine(time(NULL));
    std::uniform_int_distribution<> distribution(min, max);

    return distribution(engine);
}

double Random(double min, double max)
{
    static std::mt19937 engine(time(NULL));
    std::uniform_real_distribution<> distribution(min, max);

    return distribution(engine);
}

bool RandomOneIn(int chance)
{
    if(chance == 0)
        return false;
    return Random(1, chance) == 1;
}

bool RandomPercent(int chance)
{
    return Random(1, 100) <= chance;
}
