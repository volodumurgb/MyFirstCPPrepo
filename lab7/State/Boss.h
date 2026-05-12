#ifndef BOSS_H
#define BOSS_H

#include <memory>

class IBossState;

class Boss
{
    private:
        int health = 100;
        std::unique_ptr<IBossState> currentState;
    public:
        Boss(std::unique_ptr<IBossState> initialState);
        void ChangeState(std::unique_ptr<IBossState> state);
        void PerformAttack();
        void TakeDamage(int damage);
        void ReceiveDamage(int damage);
        int GetHealth() const;
};

#endif // BOSS_H