#pragma once

#include "Character.h"



/******************************************************************************
The human player
*******************************************************************************/
class Player : public Character
{
public:
    Player();
    virtual ~Player();

	// Implementations from base class 'Character'
	virtual bool isAlive() const;
	virtual void takeHitFrom(const Weapon *weapon);
};

