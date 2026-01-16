#include "misc.h"

float Random::GenFltNum()
{
    static std::random_device rd;
    static std::mt19937 rng(rd());

    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    return dist(rng);
}


int Random::GenIntNum()
{
    static std::random_device rd;
    static std::mt19937 rng(rd());

    std::uniform_int_distribution<int> dist(0, 255);
    return dist(rng);
}