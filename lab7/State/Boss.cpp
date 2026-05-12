#include "Boss.h"
#include "IBossState.h"
#include <iostream>

Boss::Boss(std::unique_ptr<IBossState> initialState) : currentState(std::move(initialState)), health(100) {}

void Boss::ChangeState(std::unique_ptr<IBossState> state) {
    std::cout << "Boss is changing state..." << std::endl;
    currentState = std::move(state);
}

void Boss::PerformAttack() {
    if (currentState) currentState->Attack();
}

void Boss::TakeDamage(int damage) {
    if (currentState)
    {
        currentState->TakeDamage(this, damage);
    }
    else
    {
        ReceiveDamage(damage);
    }
}

void Boss::ReceiveDamage(int damage) {
    health -= damage;
    std::cout << "Boss receives " << damage << " damage! Current health: " << health << std::endl;
    if (health < 0) health = 0;
}
int Boss::GetHealth() const {
    return health;
}