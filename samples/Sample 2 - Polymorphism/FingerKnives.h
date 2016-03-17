#pragma once

#include "Weapon.h"



/******************************************************************************
A hand glove sporting nasty knives. 
*******************************************************************************/
class FingerKnives : public Weapon
{
public:
	FingerKnives();
	virtual ~FingerKnives();

	// Implementation from base class 'Weapon'
	virtual float getDamage() const;
};

