#include <iostream>
#include "Initialisers.h"

void InitLocations(Location *locations[])
{
	
	//Location variables
	// ajacent locations vector key = { N, S , E, W }
	// challenges exit allocation = { N, S , E, W }
	// Start location - locations[0] connections to locations [0,2,3,1]
	char *startName = "Start Location";
	char *startDescription = "POP! \n You have materialised in a maze of three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> startAdjLoc = { 0,2,3,1 };
	// General Location 1 - locations[1] connects to locations[0,4,2,7]
	char *loc1Name = "Location 1";
	char *loc1Description = "Welcome to the room labeled Location 1 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc1AdjLoc = { 0,4,2,7 };
	// General Location 2 - locations[2] connects to locations[0,5,3,1]
	char *loc2Name = "Location 2";
	char *loc2Description = "Welcome to the room labeled Location 2 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc2AdjLoc = { 0,5,3,1 };
	// General Location 3 - locations[3] connects to locations[0,6,9,2]
	char *loc3Name = "Location 3";
	char *loc3Description = "Welcome to the room labeled Location 3 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc3AdjLoc = { 0,6,9,2 };
	// General Location 4 - locations[4] connects to locations[1,9,5,7]
	char *loc4Name = "Location 4";
	char *loc4Description = "Welcome to the room labeled Location 4 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc4AdjLoc = { 1,9,5,7 };
	// General Location 5 - locations[5] connects to locations[2,8,6,4]
	char *loc5Name = "Location 5";
	char *loc5Description = "Welcome to the room labeled Location 5 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc5AdjLoc = { 2,8,6,4 };
	// General Location 6 - locations[6] connects to locations[3,9,7,5]
	char *loc6Name = "Location 6";
	char *loc6Description = "Welcome to the room labeled Location 6 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc6AdjLoc = { 3,9,7,5 };
	// General Location 7 - locations[7] connects to locations[4,10,3,8]
	char *loc7Name = "Location 7";
	char *loc7Description = "Welcome to the room labeled Location 7 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc7AdjLoc = { 4,10,3,8 };
	// General Location 8 - locations[8] connects to locations[5,10,9,7]
	char *loc8Name = "Location 8";
	char *loc8Description = "Welcome to the room labeled Location 8 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc8AdjLoc = { 5,10,9,7 };
	// General Location 9 - locations[9] connects to locations[6,10,3,8]
	char *loc9Name = "Location 9";
	char *loc9Description = "Welcome to the room labeled Location 9 \n You see three twisty little passages that all look the same! \n Choose one to find your way out ;) \n ";
	std::vector<int> loc9AdjLoc = { 6,10,3,8 };
	// Finish location - locations[10] connections to locations [8,10,9,7]
	char *finishName = "Finish Location";
	char *finishDescription = "??? OH! ??? \n Well this is a suprise, I really didn't think you would get to the end :S \n My apologies as I have nothing prepared, no prize, no cake, no fan fair... \n Good Job!!? \n Please take your self satifaction elsewhere or try again ;)";
	std::vector<int> finishAdjLoc = { 8,10,9,7 };

	locations[0] = new StartLocation(startName, startDescription, startAdjLoc);
	locations[1] = new GeneralLocation(loc1Name, loc1Description, loc1AdjLoc);
	locations[2] = new GeneralLocation(loc2Name, loc2Description, loc2AdjLoc);
	locations[3] = new GeneralLocation(loc3Name, loc3Description, loc3AdjLoc);
	locations[4] = new GeneralLocation(loc4Name, loc4Description, loc4AdjLoc);
	locations[5] = new GeneralLocation(loc5Name, loc5Description, loc5AdjLoc);
	locations[6] = new GeneralLocation(loc6Name, loc6Description, loc6AdjLoc);
	locations[7] = new GeneralLocation(loc7Name, loc7Description, loc7AdjLoc);
	locations[8] = new GeneralLocation(loc8Name, loc8Description, loc8AdjLoc);
	locations[9] = new GeneralLocation(loc9Name, loc9Description, loc9AdjLoc);
	locations[10] = new FinishLocation(finishName, finishDescription, finishAdjLoc);
}

void InitFleeChallenges(Challenge *challenge[])
{
	char * challenge0 = "Can you avoid the banana peals?";
	char * challenge1 = "Can you jump the forgotten long drop of stinkiness?";
	char * challenge2 = "Can you swim the lake of despair?";
	char * challenge3 = "Can you navigate the icey pond of peas?";
	char * challenge4 = "Can you climb the waterfall of molten chocolate?";
	// difficulty set to default of 2 and weighted based on room and player at the time the challenge is taken
	int difficulty = 2;

	challenge[0] = new FleeChallenge(challenge0, difficulty);
	challenge[1] = new FleeChallenge(challenge1, difficulty);
	challenge[2] = new FleeChallenge(challenge2, difficulty);
	challenge[3] = new FleeChallenge(challenge3, difficulty);
	challenge[4] = new FleeChallenge(challenge4, difficulty);
}

void InitMentalChallenges(Challenge *challenge[])
{
	char * challenge0 = "Can you avoid the banana peals?";
	char * challenge1 = "Can you jump the forgotten long drop of stinkiness?";
	char * challenge2 = "Can you swim the lake of despair?";
	char * challenge3 = "Can you navigate the icey pond of peas?";
	char * challenge4 = "Can you climb the waterfall of molten chocolate?";
	// difficulty set to default of 2 and weighted based on room and player at the time the challenge is taken
	int difficulty = 2;
	char * answer = "yes";

	challenge[0] = new MentalChallenge(challenge0, answer, difficulty);
	challenge[1] = new MentalChallenge(challenge1, answer, difficulty);
	challenge[2] = new MentalChallenge(challenge2, answer, difficulty);
	challenge[3] = new MentalChallenge(challenge3, answer, difficulty);
	challenge[4] = new MentalChallenge(challenge4, answer, difficulty);
}

void InitPhysicalChallenges(Challenge *challenge[])
{
	char * challenge0 = "To proceed you must challenge Bill the Badger?";
	char * challenge1 = "To proceed you must challenge Richard the rooster?";
	char * challenge2 = "To proceed you must challenge Michelle the Mouse?";
	char * challenge3 = "To proceed you must challenge Susan the Lazy?";
	char * challenge4 = "To proceed you must challenge Justin the Yellow?";
	// difficulty set to default of 2 and weighted based on room and player at the time the challenge is taken
	int difficulty = 2;

	challenge[0] = new PhysicalChallenge(challenge0, difficulty);
	challenge[1] = new PhysicalChallenge(challenge1, difficulty);
	challenge[2] = new PhysicalChallenge(challenge2, difficulty);
	challenge[3] = new PhysicalChallenge(challenge3, difficulty);
	challenge[4] = new PhysicalChallenge(challenge4, difficulty);
}

void InitEnemies(Player *player[])
{
}

void InitHuman(Human human)
{


	//std::cout << "Please setup your character" << std::endl;
}
