#ifndef BIOMEFACTORIES_H
#define BIOMEFACTORIES_H

#include "IBiomeFactory.h"
#include "../Enemies/IEnemies.h"
#include "../Enemies/Enemies.h"

class ForestFactory : public IBiomeFactory {
public:
    std::unique_ptr<IMeleeEnemy> CreateMelee() const override;
    std::unique_ptr<IRangedEnemy> CreateRanged() const override;
};

class CaveFactory : public IBiomeFactory {
public:
    std::unique_ptr<IMeleeEnemy> CreateMelee() const override;
    std::unique_ptr<IRangedEnemy> CreateRanged() const override;
};

#endif