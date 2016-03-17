#include <vector>
#include "GameFunctions.h"


int PlayerMove(StringOO& move, std::vector<int> attachedLoc)
{
	// attached locations vector = { N, S , E, W }
	int newLocation;
	StringOO moveTo = move.StringLowercase();
	// set the new location variable to the corresponding room number in the attachedLoc vector
	if (moveTo.StringCompare("move north"))
	{
		newLocation = attachedLoc[0];
	}
	else if (moveTo.StringCompare("move south"))
	{
		newLocation = attachedLoc[1];
	}
	else if (moveTo.StringCompare("move east"))
	{
		newLocation = attachedLoc[2];
	}
	else if (moveTo.StringCompare("move west"))
	{
		newLocation = attachedLoc[3];
	}
	else
	{
		newLocation = -1;
	}
	return newLocation;
}

bool ValidateMove(int location1, int location2)
{
	if (location1 == location2)
	{
		std::cout << "Unfortunately that path was blocked behind you when you entered \n You will have to select a different path =O" << std::endl;
		return false;
	}
	else if (location1 == -1)
	{
		std::cout << "Please try using English to describe where you want to go :S \n - move north \n - move south \n - move east \n - move west" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

void AllocateChallenges(Location & location, Challenge & challenge, int blockedPath)
{
	// Blocked path == users last location
	// ajacent locations vector key = { N, S , E, W }
	// challenges exit allocation = { N, S , E, W }
	

	// for all available paths in the room allocate a challenge
	// SetChallenges vector with challenge array index in order of ajacent locations
}


