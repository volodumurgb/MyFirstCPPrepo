#include "BiomeFactories.h"

// ForestFactory implementation
std::unique_ptr<IMeleeEnemy> ForestFactory::CreateMelee() const
{
    return std::make_unique<Ent>();
}
std::unique_ptr<IRangedEnemy> ForestFactory::CreateRanged() const
{
    return std::make_unique<Elf>();
}

// CaveFactory implementation
std::unique_ptr<IMeleeEnemy> CaveFactory::CreateMelee() const
{
    return std::make_unique<Gnome>();
}
std::unique_ptr<IRangedEnemy> CaveFactory::CreateRanged() const
{
    return std::make_unique<LavaHound>();
}