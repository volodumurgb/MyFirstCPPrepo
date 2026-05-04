#include "Twink.h"
#include <iostream>

Twink::Twink()
{
    type = "classic twink";
}

Twink::Twink(std::string twink_type)
{
    SelectType(twink_type);
}

void Twink::SelectType(std::string type_of_twink)
{
    type = type_of_twink;
}

void Twink::SelectType()
{
    type = "classic twink";
}

void Twink::SaySomething()
{
    std::cout << "I am a " << type << " twink!" << std::endl;
}