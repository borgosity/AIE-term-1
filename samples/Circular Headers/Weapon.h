#pragma once

//#include "Character.h"

// Forward declaration
class Character;

class Weapon
{
public:
    Weapon();
    virtual ~Weapon();

    void fire();

    void setOwner(Character *owner);

private:
    Character *m_owner;
};

