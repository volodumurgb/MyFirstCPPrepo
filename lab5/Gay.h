#ifndef GAY_H
#define GAY_H

#include "LGBT.h"

class Gay : public virtual LGBT
{
public:
    Gay();
    ~Gay() override;
    void SaySomething() override;
};

#endif // GAY_H
