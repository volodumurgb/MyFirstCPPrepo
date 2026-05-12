#ifndef IBIOMEFACTORY_H
#define IBIOMEFACTORY_H
#pragma once
#include <memory>
#include "../Enemies/IEnemies.h"


class IBiomeFactory {
public:
    virtual ~IBiomeFactory() = default;
    virtual std::unique_ptr<IMeleeEnemy> CreateMelee() const = 0;
    virtual std::unique_ptr<IRangedEnemy> CreateRanged() const = 0;
};

#endif