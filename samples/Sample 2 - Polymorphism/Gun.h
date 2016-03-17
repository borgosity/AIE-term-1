#pragma once

#include "Weapon.h"



/******************************************************************************
A gun 
*******************************************************************************/
class Gun : public Weapon
{
public:
	Gun();
	virtual ~Gun();

	// Implementation from base class 'Weapon'
	virtual float getDamage() const;
};

