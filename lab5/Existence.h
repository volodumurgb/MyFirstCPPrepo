#ifndef EXISTENCE_H
#define EXISTENCE_H

#include "Trans.h"
#include "Gay.h"
#include "Bisexual.h"

class Existence : virtual public Trans, virtual public Gay, virtual public Bisexual
{
public:
    Existence();
    ~Existence() override;
    void SaySomething() override;
};

#endif // EXISTENCE_H
