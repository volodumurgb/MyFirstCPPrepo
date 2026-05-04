#include "Bisexual.h"
#include <iostream>

Bisexual::Bisexual()
{
    setRarity(4);
    setName("Lady Gaga fan");
    setClothes("Old Money style");
    std::cout << "Bisexual: We created a Bi person" << std::endl;
}
Bisexual::~Bisexual()
{
    std::cout << "Bisexual: We killed Bisexual person T_T" << std::endl;
}

void Bisexual::SaySomething()
{
    std::cout << "I am a Bisexual! I like man and woman" << std::endl;
}