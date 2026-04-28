#ifndef GAY_H
#define GAY_H

#include "LGBT.h"

class Gay : public LGBT
{
public:
    Gay();
    void SaySomething() override;
};

#endif // GAY_H
