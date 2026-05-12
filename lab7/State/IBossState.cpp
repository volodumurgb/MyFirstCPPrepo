#include "IBossState.h"
#include "Boss.h"
#include <iostream>
#include <memory>

void PhaseState1::Attack()
{
    std::cout << "Boss is attacking with PhaseState1!" << std::endl;
}

void PhaseState1::TakeDamage(Boss* boss, int damage)
{
    std::cout << "Boss takes " << damage << " damage in PhaseState1!" << std::endl;
    boss->ReceiveDamage(damage);
    if (boss->GetHealth() <= 50)
    {
        boss->ChangeState(std::make_unique<PhaseState2>());
    }
}

void PhaseState2::Attack()
{
    std::cout << "Boss is attacking with PhaseState2!" << std::endl;
}

void PhaseState2::TakeDamage(Boss* boss, int damage)
{
    std::cout << "Boss takes " << damage << " damage in PhaseState2!" << std::endl;
    boss->ReceiveDamage(damage);
    if (boss->GetHealth() <= 10)
    {
        boss->ChangeState(std::make_unique<PhaseState3>());
    }
    if (boss->GetHealth() <= 0)
    {
        std::cout << "Boss is defeated!" << std::endl;
    }
}

void PhaseState3::Attack()
{
    std::cout << "Boss is attacking with PhaseState3!" << std::endl;
}

void PhaseState3::TakeDamage(Boss* boss, int damage)
{
    std::cout << "Boss takes " << damage << " damage in PhaseState3!" << std::endl;
    boss->ReceiveDamage(damage);
    if (boss->GetHealth() <= 0)
    {
        std::cout << "Boss is defeated!" << std::endl;
    }
}
