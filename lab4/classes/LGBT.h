#ifndef LGBT_H
#define LGBT_H
#include <iostream>
#include <string>

class LGBT
{
private:
    std::string name;
    int rarity; 
    std::string clothes;
public:
    virtual ~LGBT() = default; 

    void setRarity(int level_of_rarity);
    void setName(std::string name_of_type);
    void setClothes(std::string name_of_clothes);
    virtual void SaySomething();
    void displayInfo();
};

#endif 