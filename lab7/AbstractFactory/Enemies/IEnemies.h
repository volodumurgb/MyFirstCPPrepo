#ifndef IENEMIES_H
#define IENEMIES_H

#include <memory>
#include <vector>

class IMeleeEnemy{
public:
    virtual ~IMeleeEnemy() = default;
    virtual void GetName() const = 0;
    virtual void GetHealth() const = 0;
    virtual void MeleeAttack() const = 0;
};
class IRangedEnemy{
public:
    virtual ~IRangedEnemy() = default;
    virtual void GetName() const = 0;
    virtual void GetHealth() const = 0;
    virtual void RangedAttack() const = 0;
};

#endif // IENEMIES_H