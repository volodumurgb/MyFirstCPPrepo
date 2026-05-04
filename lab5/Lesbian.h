#ifndef LESBIAN_H
#define LESBIAN_H

#include "LGBT.h"

class Lesbian : public LGBT
{
public:
    Lesbian();
    void SaySomething() override;
};

#endif // LESBIAN_H