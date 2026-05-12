#include "level.h"
#include "AbstractFactory/Factory/BiomeFactories.h"
#include "AbstractFactory/Enemies/IEnemies.h"
#include "State/IBossState.h"
#include "State/Boss.h"
#include <memory>
#include <iostream>

void LoadLevel()
{
    std::cout << "Loading level with forest enemies..." << std::endl;
    ForestFactory forestFactory;
    CaveFactory caveFactory;
    auto forestMelee = forestFactory.CreateMelee();
    auto forestRanged = forestFactory.CreateRanged();
    forestMelee->GetName();
    forestRanged->GetName();
    std::cout << "Loading level with cave enemies..." << std::endl;
    auto caveMelee = caveFactory.CreateMelee();
    auto caveRanged = caveFactory.CreateRanged();
    caveMelee->GetName();
    caveRanged->GetName();
}

void BossFight()
{
    std::cout << "Initiating boss fight..." << std::endl;
    auto boss = std::make_unique<Boss>(std::make_unique<PhaseState1>());
    boss->PerformAttack();
    boss->TakeDamage(30);
    boss->PerformAttack();
    boss->TakeDamage(50);
    boss->PerformAttack();
    boss->TakeDamage(20);
}

void level()
{
    LoadLevel();
    BossFight();
}