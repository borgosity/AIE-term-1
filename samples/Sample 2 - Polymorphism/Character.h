#pragma once

#include "GameObject.h"
#include "Weapon.h"
#include "NonCopyable.h"



/******************************************************************************
'Character' is the base class for all game characters.
*******************************************************************************/
class Character : public GameObject,
				  public NonCopyable
{
public:

	//---------------------------------
	// Operations
	//---------------------------------

	void setWeapon(Weapon *weapon);

	void clearWeapon();

	Weapon *getWeapon() const;

	float getHealth() const;



	//---------------------------------
	// Polymorphic Methods
	//---------------------------------
	// ALl derived classes MUST provide implementations for the following methods

	// return true if the character is currently alive, otherwise return false.
	virtual bool isAlive() const = 0;

	// Take whatever action is required when the character jhas been hit by
	// the specified weapon
	virtual void takeHitFrom( const Weapon *weapon ) = 0;



protected:

	Character();
    virtual ~Character();

	Weapon *m_weapon;
	float m_health;
};

