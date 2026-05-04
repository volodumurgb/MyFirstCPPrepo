#include "Existence.h"
#include <iostream>

Existence::Existence()
{
    setRarity(5);
    setName("Jamal");
    setClothes("Dinosour costume");
    std::cout << "EXISTENCE: We created an existence person (Trans, Gay, Bisexual)" << std::endl;
}
Existence::~Existence()
{
    std::cout << "Existence::We killed Existence person ;)" << std::endl;
}
void Existence::SaySomething()
{
    std::cout << "I am Trans, Gay, and Bisexual - all identities coexist, I hope!" << std::endl;
}
