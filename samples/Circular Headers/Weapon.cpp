#include "Weapon.h"



Weapon::Weapon()
{
    m_owner = nullptr;
}


Weapon::~Weapon()
{
}

void Weapon::fire()
{
}

void Weapon::setOwner(Character * owner)
{
    m_owner = owner;
}
