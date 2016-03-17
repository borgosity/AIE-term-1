#pragma once

#include <string>
#include "Character.h"
#include "Weapon.h"



/******************************************************************************
'Factory' is used to make new instances (i.e. objects) of the classes in our game.
This means that we can create new objects of particular types without having to
include the headers for that type.
'Factory' is one of the standard 'design patterns' used in Object-Oriented design.
'Factory' is an example of a 'singleton' class (also one of the standard O-O 
design patters, meaning that only one Factory object can exist during the life 
of the program.
*******************************************************************************/
class Factory
{
public:

	// Make a new Character of a specified class name. Valid class names are:
	//
	//	  Player
	//	  StartTrooper
	//	  FreddyKrueger
	//	  Gun
	//	  FingerKnives
	//
	// If the class name is not valid, the application will fail. 
	// Note that you don't need to test the returned pointer for non-null, as this 
	// method guarantees a valid return result. All objects created via this method 
	// must be destroyed by calling Factory::destroyGameObject(), i.e. the normal 
	// 'delete' operator won't work.
    static Character *makeCharacter(const std::string & className);

	// Make a new Weapon of a specified class name. Valid class names are:
	//
	//	  Gun
	//	  FingerKnives
	//
	static Weapon *makeWeapon(const std::string & className);

	// Destroy the specified game object.
	static void destroyGameObject(GameObject *gameObject);

private:
	// We make the constructor and destructor private so that the caller can ONLY
	// access the Factory via its static methods. This is what makes a singleton.
    Factory();
    ~Factory();
};

