#ifndef TRANS_H
#define TRANS_H

#include "LGBT.h"

class Trans : public virtual LGBT
{
public:
    Trans();
    ~Trans() override;
    void SaySomething() override;
};

#endif // TRANS_H