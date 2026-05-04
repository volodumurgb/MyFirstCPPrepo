#include "LGBT.h"
LGBT::LGBT()
{
    std::cout << "LGBT: We created a LGBT person" << std::endl;
}
LGBT::~LGBT()
{
    std::cout << "LGBT::We killed LGBT person :(" << std::endl;
}
void LGBT::setRarity(int level_of_rarity) { rarity = level_of_rarity; }
void LGBT::setName(std::string name_of_type) { name = name_of_type; }
void LGBT::setClothes(std::string name_of_clothes) { clothes = name_of_clothes; }
void LGBT::SaySomething()
{
    std::cout << "ЯЛКВМОМ" << std::endl;
}
void LGBT::displayInfo()
{
    std::cout << "I am a " << rarity << " rarity, my name is " << name << " and I am wearing " << clothes << std::endl;
}