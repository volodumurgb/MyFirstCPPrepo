#include "Trans.h"
#include <iostream>

Trans::Trans()
{
    setRarity(3);
    setName("Alex");
    setClothes("Modern Outfit");
    std::cout << "TRANS: We created a trans person" << std::endl;
}
Trans::~Trans()
{
    std::cout << "Trans::We killed Trans person :(" << std::endl;
}
void Trans::SaySomething()
{
    std::cout << "I am trans! My identity is valid" << std::endl;
}
