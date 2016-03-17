#include <iostream>
#include <vector>

#include "StringOO.h"
#include "Initialisers.h"
#include "GameFunctions.h"

int main()
{
	// user input variables
	const int userInputLimit = 11;
	char userInput[userInputLimit] = {};
	bool humanFinished = false;
	bool moveHuman = false;
	StringOO humanMove = "move south";

	// location variables
	const int locationNum = 11;
	Location *locations[locationNum] = {};
	int prevLocation = 0;
	int newLocation = 0;
	int finishLocation = locationNum - 1;

	// human player variables
	int humanLoc = 0;
	const char * name = "Barry";
	int strength = 10;
	int health = 100;
	int luck = 10;
	int intellegence = 10;

	// challenges variables
	const int challengeNum = 5;
	Challenge *fleeChallenges[challengeNum] = {};
	Challenge *mentalChallenges[challengeNum] = {};
	Challenge *physicalChallenges[challengeNum] = {};

	// initialise locations
	InitLocations(locations);

	// initialise human
	Human human(humanLoc, name, strength, health, luck, intellegence);

	// initialise challenges
	InitFleeChallenges(fleeChallenges);
	InitMentalChallenges(mentalChallenges);
	InitPhysicalChallenges(physicalChallenges);

	// Game loop
	while (!humanFinished)
	{
		// print out details of room
		std::cout << locations[human.GetLocation()]->GetDescription() << std::endl;
		while (!moveHuman)
		{
			// get user to enter move
			std::cin.getline(userInput, userInputLimit);
			humanMove = userInput;
			// determine the new location
			newLocation = PlayerMove(humanMove, locations[human.GetLocation()]->GetAjacentLoc());
			// validate users move and if validate change their location
			if (ValidateMove(newLocation, prevLocation))
			{
				// assign a challenge to an exit

				prevLocation = human.GetLocation();
				human.SetLocation(newLocation);
				moveHuman = true;
			}
			else
			{
				moveHuman = false;
			}
		}
		// reset move
		moveHuman = false;
		//check if user is in the finish location
		if (human.GetLocation() == finishLocation)
		{
			humanFinished = true;
			std::cout << locations[human.GetLocation()]->GetDescription() << std::endl;
		}

	}
	
	return 0;
}

