#pragma once

#include "Character.h"



/******************************************************************************
*******************************************************************************/
class StarTrooper : public Character
{
public:
    StarTrooper();
    virtual ~StarTrooper();

	// Implementations from base class 'Character'
	virtual bool isAlive() const;
	virtual void takeHitFrom(const Weapon *weapon);
};

