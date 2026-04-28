#include "Gay.h"
#include <iostream>

Gay::Gay()
{
    setRarity(4);
    setName("Joey Mills");
    setClothes("Strip Club Outfit");
}

void Gay::SaySomething()
{
    std::cout << "I am a gay! I like men" << std::endl;
}
