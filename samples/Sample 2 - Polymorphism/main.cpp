#include "Factory.h"
#include "Character.h"
#include "Weapon.h"
#include <iostream>



/******************************************************************************
*******************************************************************************/
void showStatus(const Character *character)
{
	std::cout << "Character health is  "
		      << character->getHealth()
		      << " and is  "
			  << (character->isAlive() ? "ALIVE!" : "DEAD!!!!")
			  << "\n\n";
}

/******************************************************************************
*******************************************************************************/
void main()
{
    std::cout << "Running:\n\n";

	// Create some game characters
    Character *me      = Factory::makeCharacter("Player");
	Character *trooper = Factory::makeCharacter("StarTrooper");
	Character *freddy  = Factory::makeCharacter("FreddyKrueger");

	// ...and fit them out with some weapons
	trooper->setWeapon(Factory::makeWeapon("Gun"));
	freddy->setWeapon(Factory::makeWeapon("FingerKnives"));

	// Show initial player status
	showStatus( me );

	//
	// The player takes a hit from various characters and displays status 
	// after each hit
	//

	me->takeHitFrom( trooper->getWeapon() );
	showStatus( me );

	me->takeHitFrom(freddy->getWeapon());
	showStatus(me);

	me->takeHitFrom(freddy->getWeapon());
	showStatus(me);

	// Finally, clean up the main game objects
	Factory::destroyGameObject(me);
	Factory::destroyGameObject(trooper);
	Factory::destroyGameObject(freddy);

	std::cout << "\n\nFinished successfully:\n\n";
}