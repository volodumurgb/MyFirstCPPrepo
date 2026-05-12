#ifndef ENEMIES_H
#define ENEMIES_H

#include "IEnemies.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

//forest enemies
class Ent:public IMeleeEnemy
{
    public:
        void MeleeAttack() const override { std::cout << "Ent performs a melee attack!" << std::endl; }
        void GetName() const override { std::cout << "Ent" << std::endl; }
        void GetHealth() const override { std::cout << "Health: 150" << std::endl; }
};
class Elf:public IRangedEnemy
{
    public:
        void RangedAttack() const override { std::cout << "Elf performs a ranged attack!" << std::endl; }
        void GetName() const override { std::cout << "Elf" << std::endl; }
        void GetHealth() const override { std::cout << "Health: 100" << std::endl; }
};

//cave enemies
class LavaHound:public IRangedEnemy
{
    public:
        void RangedAttack() const override { std::cout << "Lava Hound performs a ranged attack!" << std::endl; }
        void GetName() const override { std::cout << "Lava Hound" << std::endl; }
        void GetHealth() const override { std::cout << "Health: 200" << std::endl; }
};
class Gnome:public IMeleeEnemy
{
    public:
        void MeleeAttack() const override { std::cout << "Gnome performs a melee attack!" << std::endl; }
        void GetName() const override { std::cout << "Gnome" << std::endl; }
        void GetHealth() const override { std::cout << "Health: 80" << std::endl; }
};

#endif 