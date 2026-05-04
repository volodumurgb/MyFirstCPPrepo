#ifndef TWINK_H
#define TWINK_H

#include "Gay.h"
#include <string>

class Twink : public Gay
{
private:
    std::string type;

public:
    Twink();
    Twink(std::string twink_type);

    void SelectType(std::string type_of_twink);
    void SelectType();

    void SaySomething() override;
};

#endif // TWINK_H