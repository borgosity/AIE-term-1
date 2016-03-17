#include <random>
#include <vector>
#include "GameFunctions.h"
#include "MersenneTwister.h"





void GameEngine()
{
	// user input variables
	const int userInputLimit = 11;
	char userInput[userInputLimit] = {};
	bool humanFinished = false;
	bool moveHuman = false;
	StringOO humanMove = "move south";

	// location variables
	const int locationNum = 11;
	Location *Locations[locationNum] = {};
	int prevLocation = 0;
	int newLocation = 0;
	int finishLocation = locationNum - 1;

	// human player variables
	int humanLoc = 0;
	StringOO name = "Barry";
	int strength = 10;
	int health = 100;
	int luck = 10;
	int intellegence = 10;

	// challenges variables
	const int challengeNum = 15;
	Challenge *Challenges[challengeNum] = {};
	//Challenge *fleeChallenges[challengeNum] = {};
	//Challenge *mentalChallenges[challengeNum] = {};
	//Challenge *physicalChallenges[challengeNum] = {};

	// initialise Locations
	InitLocations(Locations);

	// initialise human
	Human Human(humanLoc, name, strength, health, luck, intellegence);

	// initialise Challenges
	InitChallenges(Challenges);
	AllocateChallenges(Locations, locationNum);


	// Game loop
	while (!humanFinished)
	{
		// print out details of room
		std::cout << Locations[Human.GetLocation()]->GetDescription() << std::endl;
		while (!moveHuman)
		{
			// get user to enter move
			std::cin.getline(userInput, userInputLimit);
			std::cout << "\n###===========================================================================##\n";
			humanMove = userInput;
			//humanMove = "move south";
			// determine the new location
			newLocation = PlayerMove(Human, humanMove, Locations[Human.GetLocation()]->GetAjacentLoc());
			// validate users move and if validate change their location
			if (ValidateMove(newLocation, prevLocation))
			{
				Human.SetChallenge(Locations[Human.GetLocation()]->GetPathChallenge(Human.GetHeading()));
				// challenge User
				ApplyChallenge(*Challenges[Human.GetChallenge()], Human);
				// move user to new location
				prevLocation = Human.GetLocation();
				Human.SetPrevHeading(Human.GetHeading());
				Human.SetLocation(newLocation);
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
		if (Human.GetLocation() == finishLocation)
		{
			humanFinished = true;
			std::cout << Locations[Human.GetLocation()]->GetDescription() << std::endl;
		}

	}
	DestroyLocations(Locations, locationNum);
	DestroyChallenges(Challenges, challengeNum);
	//DestroyEnemies(player, length);
}

int PlayerMove(Human & human, StringOO & move, std::vector<int> attachedLoc)
{
	// attached locations vector = { N, S , E, W }
	int newLocation = 0;
	StringOO moveTo = move.StringLowercase();
	// set the new location variable to the corresponding room number in the attachedLoc vector
	if (moveTo.StringCompare("move north"))
	{
		newLocation = attachedLoc[0];
		human.SetHeading(0);
	}
	else if (moveTo.StringCompare("move south"))
	{
		newLocation = attachedLoc[1];
		human.SetHeading(1);
	}
	else if (moveTo.StringCompare("move east"))
	{
		newLocation = attachedLoc[2];
		human.SetHeading(2);
	}
	else if (moveTo.StringCompare("move west"))
	{
		newLocation = attachedLoc[3];
		human.SetHeading(3);
	}
	else
	{
		newLocation = -1;
	}
	return newLocation;
}

bool ValidateMove(int newLocation, int prevLocation)
{
	if (newLocation == prevLocation)
	{
		std::cout << "> Unfortunately that path was blocked behind you when you entered \n You will have to select a different path =O" << std::endl;
		return false;
	}
	else if (newLocation == -1)
	{
		std::cout << "> Please try using English to describe where you want to go :S \n - move north \n - move south \n - move east \n - move west" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

void AllocateChallenges(Location & Locale, Human & Human)
{
	// Challenges exit allocation = { N, S , E, W }
	int vectorSize = 4;
	std::vector<int> challVector(vectorSize);

	for (int i = 0; i < vectorSize; i++)
	{
		challVector[i] = RandomNum(0, 16);
	}
	Locale.SetChallenges(challVector);
}

void AllocateChallenges(Location *Locations[], int locSize)
{
	// Challenges exit allocation = { N, S , E, W }
	int vectorSize = 4;
	std::vector<int> challVector(vectorSize);

	for (int i = 0; i < locSize; i++)
	{
		challVector = { 0,0,0,0 };
		for (int j = 0; j < vectorSize; j++)
		{
			challVector[j] = rand() % 16;
		}
		Locations[i]->SetChallenges(challVector);
	}

}

void ApplyChallenge(Challenge & Challenge, Human & HumanObj)
{
	std::cout << Challenge.GetDescription() << std::endl;
}

void Combat(Human & HumanObj, Enemy & EnemyObj)
{
	if (HumanObj.GetStrength() >= EnemyObj.GetStrength() && HumanObj.GetLuck() >= EnemyObj.GetLuck())
	{
		// wins hands down
		if (BestOfThree())
		{
			std::cout << "^^ You are a formidable foe, you fight " << EnemyObj.GetName() << " and win easily \n   You feast on the still beating heart of your foe and gain health and strength \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetStrength(HumanObj.GetStrength() + 2);
			std::cout << "  -   Health: " << HumanObj.GetHealth() << std::endl;
			std::cout << "  - Strength: " << HumanObj.GetStrength() << std::endl;
		}
		else
		{
			std::cout << "^^ You are a formidable foe, you fight " << EnemyObj.GetName() << " and win easily \n   However, you took a hit that is but a flesh wound, your health is tarnished but a bit \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			std::cout << "  -   Health: " << HumanObj.GetHealth() << std::endl;
			std::cout << "  - Strength: " << HumanObj.GetStrength() << std::endl;
		}

	}
	else if (HumanObj.GetHealth() >= EnemyObj.GetHealth() && HumanObj.GetLuck() >= EnemyObj.GetLuck())
	{
		// player gets lucky takes a few but wins
		if (BestOfThree())
		{
			std::cout << "^^ Your enemy is your equal, you fight " << EnemyObj.GetName() << " and get lucky \n   You feast on the still beating heart of your foe and gain health and luck \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			std::cout << "  - Health: " << HumanObj.GetHealth() << std::endl;
			std::cout << "  -   Luck: " << HumanObj.GetLuck() << std::endl;
		}
		else
		{
			std::cout << "^^ Your enemy is your equal, you fight " << EnemyObj.GetName() << " and get lucky \n   However, you took a hit that is but a flesh wound, your health is tarnished but a bit \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			std::cout << "  - Health: " << HumanObj.GetHealth() << std::endl;
			std::cout << "  -   Luck: " << HumanObj.GetLuck() << std::endl;
		}
	}
	else if (HumanObj.GetHealth() < EnemyObj.GetHealth() && HumanObj.GetLuck() >= EnemyObj.GetLuck())
	{
		// player gets lucky
		if (BestOfThree())
		{
			std::cout << "^^ Your enemy is healthier than you, you fight " << EnemyObj.GetName() << " and get lucky \n   You feast on the still beating heart of your foe and gain health and luck \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			std::cout << "  - Health: " << HumanObj.GetHealth() << std::endl;
			std::cout << "  -   Luck: " << HumanObj.GetLuck() << std::endl;
		}
		else
		{
			std::cout << "^^ Your enemy is healthier than you, you fight " << EnemyObj.GetName() << " and get lucky \n   However, you took a hit that is but a flesh wound, your health is tarnished but a bit \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			std::cout << "  - Health: " << HumanObj.GetHealth() << std::endl;
			std::cout << "  -   Luck: " << HumanObj.GetLuck() << std::endl;
		}
	}
	else
	{
		// player loses takes some damage
		std::cout << "^^ Your enemy is stronger, healthier and luckier than you, you fight " << EnemyObj.GetName() << " and you lose and flee... \n   You took a big hit that has sapped your health, strength and lost a lucky charm \n";
		HumanObj.SetHealth(HumanObj.GetHealth() - 20);
		HumanObj.SetStrength(HumanObj.GetStrength() -2);
		HumanObj.SetLuck(HumanObj.GetLuck() -2);
		std::cout << "  - Health: " << HumanObj.GetHealth() << std::endl;
		std::cout << "  - Strength: " << HumanObj.GetStrength() << std::endl;
		std::cout << "  -   Luck: " << HumanObj.GetLuck() << std::endl;
	}
}

bool BestOfThree()
{
	int wins = 0;
	int loses = 0;
	int a = 0;
	int b = 0;
	int count = 0;

	while (count != 3)
	{
		a = std::rand() % 100;
		b = std::rand() % 100;
		if (a > b)
		{
			wins++;
			count++;
		}
		else if (a < b)
		{
			loses++;
			count++;
		}
		else
		{
			continue;
		}
	}

	if (wins > loses)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int RandomNum(int min, int maxPlusOne)
{
	aie::MersenneTwister randomNum;
	int seed = randomNum.randInt() + 7;
	int genNum = 0;

	randomNum.setSeed(seed);

	if (min != 0)
	{
		while (genNum < min)
		{
			genNum = randomNum.randInt() % maxPlusOne;
		}
	}
	else
	{
		genNum = randomNum.randInt() % maxPlusOne;
	}

	return genNum;
}


