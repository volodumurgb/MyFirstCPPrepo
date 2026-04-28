#ifndef FEMBOY_H
#define FEMBOY_H

#include "Twink.h"
#include <string>

class Femboy : public Twink
{
private:
    std::string OF;
    std::string pronouns;

public:
    Femboy(std::string OF_link, std::string pronouns_of_femboy, std::string twink_type);

    void setOF(std::string OF_link);
    void setPronouns(std::string pronouns_of_femboy);

    void SaySomething() override;
};

#endif // FEMBOY_H
