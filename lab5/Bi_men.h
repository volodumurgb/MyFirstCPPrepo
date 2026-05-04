#ifndef BI_MEN_H
#define BI_MEN_H

#include "Gay.h"
#include "Bisexual.h"

class BiMen : public Gay, public Bisexual
{
public:
	BiMen();
	~BiMen() override;
	void SaySomething() override;
};

#endif // BI_MEN_H
