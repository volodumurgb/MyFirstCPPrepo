#include "Femboy.h"
#include <iostream>

Femboy::Femboy(std::string OF_link, std::string pronouns_of_femboy, std::string twink_type)
    : Twink(twink_type), OF(OF_link), pronouns(pronouns_of_femboy)
{
    setRarity(5);
}

void Femboy::setOF(std::string OF_link)
{
    OF = OF_link;
}

void Femboy::setPronouns(std::string pronouns_of_femboy)
{
    pronouns = pronouns_of_femboy;
}

void Femboy::SaySomething()
{
    std::cout << "UWU :3" << std::endl;
    std::cout << "My OF is " << OF << " and my pronouns are " << pronouns << std::endl;
}
