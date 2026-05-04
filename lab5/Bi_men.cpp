#include "Bi_men.h"
#include <iostream>

BiMen::BiMen()
{
    setRarity(4);
    setName("Latentnui Gay");
    setClothes("HelloKitty underwear");
    std::cout << "BiMen: We created a Bimen person" << std::endl;
}

BiMen::~BiMen()
{
    std::cout << "BiMen::We killed BiMen person :)" << std::endl;
}

void BiMen::SaySomething()
{
    std::cout << "I am a men! I like men and women" << std::endl;
}