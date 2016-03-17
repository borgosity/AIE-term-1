#include "Factory.h"
#include "Player.h"
#include "StarTrooper.h"
#include "Gun.h"
#include "FingerKnives.h"
#include "FreddyKrueger.h"
#include "Error.h"
#include <iostream>



/******************************************************************************
*******************************************************************************/
void Factory::destroyGameObject(GameObject * object)
{
	if (object)
	{
		delete object;
	}
}

/******************************************************************************
*******************************************************************************/
Character *Factory::makeCharacter(const std::string & className)
{
	Character *character = 0;

	if (className == "Player")
	{
		character = new Player;
	}
	else if (className == "StarTrooper")
	{
		character = new StarTrooper;
	}
	else if (className == "FreddyKrueger")
	{
		character = new FreddyKrueger;
	}
	else
	{
		// Fail the program if the class name is not one of the valid class names
		FATAL_ERROR("Invalid character class name: \"" << className << "\"");
	}

	// Note that we don't assume that the 'new' operator will always work. 'new' 
	// may fail if the heap has previously been corrupted (e.g. by a double delete).
	if (character == 0)
	{
		FATAL_ERROR("Heap failure");
	}

	// If we get through to here, then we know that we have a valid character object 
	// that is guaranteed to be safe to return to the caller.
	return character;
}

/******************************************************************************
*******************************************************************************/
Weapon *Factory::makeWeapon(const std::string & className)
{
	Weapon *weapon = 0;

	if (className == "Gun")
	{
		weapon = new Gun;
	}
	else if (className == "FingerKnives")
	{
		weapon = new FingerKnives;
	}
	else
	{
		// Fail the program if the class name is not one of the valid class names
		FATAL_ERROR("Invalid weapon class name: \"" << className << "\"");
	}

	// Note that we don't assume that the 'new' operator will always work. 'new' 
	// may fail if the heap has previously been corrupted (e.g. by a double delete).
	if (weapon == 0)
	{
		FATAL_ERROR("Heap failure");
	}

	// If we get through to here, then we know that we have a valid weapon object 
	// that is guaranteed to be safe to return to the caller.
	return weapon;
}
