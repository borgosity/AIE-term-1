#pragma once

#include "GameObject.h"



/******************************************************************************
'Weapon' is the base class for all weapons used in the game.
*******************************************************************************/
class Weapon : public GameObject
{
public:


	//---------------------------------
	// Polymorphic Methods
	//---------------------------------

	// Returns the amount of damage inflicted by the Weapon
	virtual float getDamage() const = 0;

protected:

	Weapon();
	virtual ~Weapon();
};

