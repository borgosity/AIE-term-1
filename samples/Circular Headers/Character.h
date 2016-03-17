#pragma once

#include <vector>

//#include "Weapon.h"

// Forward declaration
class Weapon;

class Character
{
public:
    Character();
    virtual ~Character();

    void addWeapon(Weapon *weapon);

private:

    std::vector<Weapon *> m_weapons;
};

