#ifndef IBOSSSTATE_H
#define IBOSSSTATE_H

class Boss;

class IBossState
{
    public:
        virtual ~IBossState() = default;
        virtual void Attack() = 0;
        virtual void TakeDamage(Boss* boss, int damage) = 0;
};

class PhaseState1 : public IBossState 
{
    public:
        void Attack() override;
        void TakeDamage(Boss* boss, int damage) override;
};

class PhaseState2 : public IBossState 
{
    public:
        void Attack() override;
        void TakeDamage(Boss* boss, int damage) override;
};

class PhaseState3 : public IBossState 
{
    public:
        void Attack() override;
        void TakeDamage(Boss* boss, int damage) override;
};

#endif 