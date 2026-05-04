#include "Gay.h"
#include <iostream>

Gay::Gay()
{
    setRarity(4);
    setName("Joey Mills");
    setClothes("Strip Club Outfit");
    std::cout << "GAY: We created a gay person" << std::endl;
}
Gay::~Gay()
{
    std::cout << "Gay::We killed Gay person :((" << std::endl;
}
void Gay::SaySomething()
{
    std::cout << "I am a gay! I like men" << std::endl;
}