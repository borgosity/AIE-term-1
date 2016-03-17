#pragma once

#include "Character.h"



/******************************************************************************
The character Freddy Krueger from "Nightmare on Elm Street"
*******************************************************************************/
class FreddyKrueger : public Character
{
public:
    FreddyKrueger();
    virtual ~FreddyKrueger();

	// Implementations from base class 'Character'
	virtual bool isAlive() const;
	virtual void takeHitFrom(const Weapon *weapon);
};

