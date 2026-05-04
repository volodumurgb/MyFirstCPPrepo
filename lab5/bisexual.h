#ifndef BISEXUAL_H
#define BISEXUAL_H

#include "LGBT.h"

class Bisexual : public virtual LGBT
{
public:
	Bisexual();
	~Bisexual() override;
	void SaySomething() override;
};

#endif //BISEXUAL_H
