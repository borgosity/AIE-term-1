#include "Character.h"
#include "Weapon.h"   


Character::Character()
{
}


Character::~Character()
{
}

void Character::addWeapon(Weapon *weapon)
{
    m_weapons.push_back(weapon);
    weapon->setOwner(this);
}
