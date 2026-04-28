#include "Lesbian.h"
#include <iostream>

Lesbian::Lesbian()
{
    setRarity(4);
    setName("Zoe");
    setClothes("Pink Dress");
}

void Lesbian::SaySomething()
{
    std::cout << "I am a Lesbian! Scissors are the best" << std::endl;
}
