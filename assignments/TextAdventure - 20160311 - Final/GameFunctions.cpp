#include <random>
#include <vector>
#include <thread>
#include <chrono>

#include "GameFunctions.h"
#include "Initialisers.h"
#include "Question.h"
#include "Enemy.h"

/*******************************************************************************************************
* GANE ENGINE - handles the looping of the game
*******************************************************************************************************/
void GameEngine()
{
	// user input variables
	const int userInputLimit = 11;
	char userInput[userInputLimit] = {};
	bool humanFinished = false;
	bool moveHuman = false;
	StringOO humanMove = "move south";
	int loopCount = 0;

	// location variables
	const int locationNum = 11;
	Location *Locations[locationNum] = {};
	int prevLocation = 0;
	int newLocation = 0;
	int finishLocation = locationNum - 1;

	// human player variables
	int humanLoc = 0;
	StringOO name = "Bruce";
	int strength = 10;
	int health = 100;
	int luck = 10;
	int intellegence = 10;

	// enemy variables
	const int enemyNum = 5;
	Enemy * Enemies[enemyNum] = {};

	// challenges variables
	const int challengeNum = 16;
	Challenge *Challenges[challengeNum] = {};

	// initialise Locations
	InitLocations(Locations);

	// initialise human
	Human Human(humanLoc, name, strength, health, luck, intellegence);

	// initialise Enemies
	InitEnemies(Enemies, enemyNum);

	// initialise Challenges
	InitChallenges(Challenges);
	//AllocateChallenges(Locations, locationNum);
	AllocateChallengesManually(Locations, locationNum);
	AddEnemyToChallenge(Challenges, enemyNum, challengeNum);

	// initial splash screen
	SetConsole();
	StartText(Human);

	// Game loop
	while (!humanFinished)
	{
		// print out details of room
		std::cout << Locations[Human.GetLocation()]->GetDescription() << std::endl;
		while (!moveHuman)
		{
			// get user to enter move
			std::cout << "+ ";
			std::cin.getline(userInput, userInputLimit);
			std::cout << std::endl;
			humanMove = userInput;
			if (loopCount == 5)
			{
				std::cout << "\n     ENOUGH ALREADY...YOUR MOVING SOUTH!! \n\n";
				//bored of guesses
				humanMove = "move south";
				loopCount = 0;
			}
			// determine the new location
			newLocation = PlayerMove(Human, humanMove, Locations[Human.GetLocation()]->GetAjacentLoc());

			// validate users move and if validate change their location
			if (ValidateMove(newLocation, prevLocation))
			{
				// set challenge user has to perform before progrogressing to the next room
				Human.SetChallenge(Locations[Human.GetLocation()]->GetPathChallenge(Human.GetHeading()));
				// challenge User
				Challenge *ChallengePtr = Challenges[Human.GetChallenge()];
				ApplyChallenge(ChallengePtr, Human, Enemies);
				// move user to new location
				prevLocation = Human.GetLocation();
				Human.SetPrevHeading(Human.GetHeading());
				Human.SetLocation(newLocation);
				moveHuman = true;
				loopCount = 0;
				std::cout << "\n***----------------------------*  pop!  *-------------------------------------**\n\n";
			}
			else
			{
				// invalid move try again
				moveHuman = false;
				loopCount++;
			}
		}
		// reset move
		moveHuman = false;
		//check if user is in the finish location
		if (Human.GetLocation() == finishLocation)
		{
			humanFinished = true;
			std::cout << Locations[Human.GetLocation()]->GetDescription() << std::endl;
			FinishText(Human);
		}

	}
	//DestroyEnemies(Enemies, enemyNum);
	for (int i = 0; i < enemyNum; i++)
	{
		delete Enemies[i];
	}
	//DestroyChallenges(Challenges, challengeNum);
	for (int i = 0; i < challengeNum; i++)
	{
		delete Challenges[i];
	}
	//DestroyLocations(Locations, locationNum);
	for (int i = 0; i < locationNum; i++)
	{
		delete Locations[i];
	}

}
/*******************************************************************************************************
* PALYER MOVE - checks user input and sets thier heading
*******************************************************************************************************/
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
/*******************************************************************************************************
* VALIDATE MOVE - confirms that the user isn't trying to go backwards
*******************************************************************************************************/
bool ValidateMove(int newLocation, int prevLocation)
{
	if (newLocation == prevLocation)
	{
		std::cout << "\n!> Unfortunately that path was blocked behind you when you entered \n   You will have to select a different path =O\n" << std::endl;
		return false;
	}
	else if (newLocation == -1)
	{
		std::cout << "\n!> Please try using English to describe where you want to go :S \n  - move north \n  - move south \n  - move east \n  - move west\n" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}
/*******************************************************************************************************
* ALLOCATE CHALLENGES (single location)- randomly allocates a challenge to each exit of a location
*******************************************************************************************************/
void AllocateChallenges(Location & Locale, Human & Human)
{
	// Challenges exit allocation = { N, S , E, W }
	/* Challenges:
	- 0     = no challenge
	- 1-5   = flee challenge
	- 6-10  = mental challenge
	- 10-15 = physical challenge
	*/
	int vectorSize = 4;
	std::vector<int> challVector(vectorSize);

	for (int i = 0; i < vectorSize; i++)
	{
		challVector[i] = std::rand() % 16;
	}
	Locale.SetChallenges(challVector);
}
/*******************************************************************************************************
* ALLOCATE CHALLENGES (array of location)- randomly allocates a challenge to each exit of a location
*******************************************************************************************************/
void AllocateChallenges(Location *Locations[], int locSize)
{
	// Challenges exit allocation = { N, S , E, W }
	/* Challenges:
	- 0     = no challenge
	- 1-5   = flee challenge
	- 6-10  = mental challenge
	- 10-15 = physical challenge
	*/
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
/*******************************************************************************************************
* ALLOCATE CHALLENGES MANUALLY - less random allocation of challenges to each exit of a location
*******************************************************************************************************/
void AllocateChallengesManually(Location *Locations[], int locSize)
{
	// Challenges exit allocation = { N, S , E, W }
	/* Challenges:
	    - 0     = no challenge
	    - 1-5   = flee challenge = rand() % 5 + 1;
	    - 6-10  = mental challenge = rand() % 5 + 6;
	    - 10-15 = physical challenge = rand() % 5 + 10;
	*/
	int vectorSize = 4;
	std::vector<int> challVector(vectorSize);

	for (int i = 0; i < locSize; i++)
	{
		challVector = { 0,0,0,0 };
		if (i == 0)
		{
			// { none, mental, physical, flee }
			challVector[0] = 0;
			challVector[1] = 6;
			challVector[2] = 10;
			challVector[3] = 1;
		}
		else if (i > 0 && i < 4)
		{
			// { none, physical, flee, mental }
			challVector[0] = 0;
			challVector[1] = rand() % 5 + 10;
			challVector[2] = rand() % 5 + 1;
			challVector[3] = rand() % 5 + 6;
		}
		else if (i > 3 && i < 7)
		{
			// { none, flee, mental, physical }
			challVector[0] = 0;
			challVector[1] = rand() % 5 + 1;
			challVector[2] = rand() % 5 + 6;
			challVector[3] = rand() % 5 + 10;
		}
		else if (i > 6 && i < 10)
		{
			// { none, mental, physical, flee }
			challVector[0] = 0;
			challVector[1] = rand() % 5 + 6;
			challVector[2] = rand() % 5 + 10;
			challVector[3] = rand() % 5 + 1;
		}
		Locations[i]->SetChallenges(challVector);
	}
}

/*******************************************************************************************************
* APPLY CHALLENGE - for the users chosen path, action the challenge for that direction
*******************************************************************************************************/
void ApplyChallenge(Challenge * ChallengePtr, Human & HumanObj, Enemy *Enemies[])
{
	//metal challenge variables
	bool incorrect = true;
	int count = 0;
	const int userInputLimit = 25;
	char userInput[userInputLimit] = {};
	StringOO userAnswer;
	StringOO actualAnswer;
	// points
	int points = ChallengePtr->GetDifficulty() + HumanObj.GetLocation();
	// if the challenge is of type FLEE
	if (ChallengePtr->GetType() == "flee")
	{
		std::cout << ">> To proceed in this direction we shall find out first if you can... \n";
		std::cout << ChallengePtr->GetDescription() << std::endl;
		Pause();
		if (BestOfThree())
		{
			std::cout << "+> Turns out yes, yes you can...you're free to pass! \n";
			HumanStats(HumanObj);
		}
		else
		{
			std::cout << "-> Nope, you can't as it turns out... \n   Someone had to come in and save you from yourself...\n   and further embarrassment...\n   Your fumbling has cost you health, strength, luck and intelligence." << std::endl;
			HumanObj.SetHealth(HumanObj.GetHealth() - points);
			HumanObj.SetStrength(HumanObj.GetStrength() - 2);
			HumanObj.SetLuck(HumanObj.GetLuck() - 2);
			HumanObj.SetIntelligence(HumanObj.GetIntelligence() - 1);
			HumanStats(HumanObj);
		}
		Pause();
	}
	// if the challenge is of type MENTAL
	else if (ChallengePtr->GetType() == "mental")
	{
		actualAnswer = ChallengePtr->GetAnswer();
		std::cout << ">> To proceed in this direction you must answer a question correctly... \n";
		std::cout << ChallengePtr->GetQuestion() << std::endl;
		while (incorrect)
		{
			std::cout << std::endl << "+ ";
			std::cin.getline(userInput, userInputLimit);
			userAnswer = userInput;
			if (userAnswer.StringCompare(actualAnswer) && count == 0)
			{
				std::cout << "\n+> Correct, please pass GO...Umm? but there is no $200 for you to collect... \n   At least you have your health ;-)" << std::endl;
				Pause();
				HumanStats(HumanObj);
				incorrect = false;
			}
			else if (userAnswer.StringCompare(actualAnswer) && count > 0)
			{
				std::cout << "-> Really? " << count << " guesses! Stop drinking the Coolade!, don't pass GO...! \n"; 
				points += count;
				std::cout << "   And give me " << points << " points of your best health and " << count << " of your intelligences... \n " << std::endl;
				Pause();
				HumanObj.SetHealth(HumanObj.GetHealth() - points);
				HumanObj.SetIntelligence(HumanObj.GetIntelligence() - count);
				HumanStats(HumanObj);
				incorrect = false;
			}
			else if (!userAnswer.StringCompare(actualAnswer) && count != 4)
			{
				std::cout << "\n   NOPE!! Try again...\n";
				count++;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "\n-> STOP!!...  <- \n             I think thats enough don't you?! \n";
				points += count;
				std::cout << "   For that you can give me...\n   - " << points << " points of your best health and...\n   - " << count << " of your intelligences... \n " << std::endl;
				Pause();
				HumanObj.SetHealth(HumanObj.GetHealth() - points);
				HumanObj.SetIntelligence(HumanObj.GetIntelligence() - count);
				HumanStats(HumanObj);
				incorrect = false;
			}
		}

	}
	// if the challenge is of type PHYSICAL
	else if (ChallengePtr->GetType() == "physical")
	{
		std::cout << ChallengePtr->GetDescription() << std::endl;
		Pause();
		Combat(HumanObj, Enemies[ChallengePtr->GetEnemy()]);
	}
	// if the challenge has no type
	else
	{
		std::cout << "   AND...\n" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "           ...NOTHING HAPPENED!! \n" << std::endl;
		std::cout << "   Get out of Gaol Free or Just Visiting, either way your free to pass!! \n" << std::endl;
		Pause();
		HumanStats(HumanObj);
	}
}
/*******************************************************************************************************
* COMBAT - called when a physical challenge is actioned
*******************************************************************************************************/
void Combat(Human & HumanObj, Enemy * EnemyObj)
{
	// enemy variables
	const char * enemyName = EnemyObj->GetName();
	int enemyHealth = EnemyObj->GetHealth();
	int enemyStrength = EnemyObj->GetStrength();
	int enemyLuck = EnemyObj->GetLuck();

	// conditional block to determine outcome of confrontations
	if (HumanObj.GetStrength() >= enemyStrength && HumanObj.GetLuck() >= enemyLuck)
	{
		// wins hands down
		if (BestOfThree())
		{
			std::cout << "^^ You are a formidable foe, you fight " << enemyName << " and win easily \n   You feast on the still beating heart of your foe...\n   You gain health and strength. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetStrength(HumanObj.GetStrength() + 2);
			HumanStats(HumanObj);
		}
		else
		{
			std::cout << "^^ You are a formidable foe, you fight " << enemyName << " and win easily \n   However, you took a hit that is but a flesh wound...\n   Your health is tarnished but a bit. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanStats(HumanObj);
		}
		Pause();
	}
	else if (HumanObj.GetHealth() >= enemyHealth && HumanObj.GetLuck() >= enemyLuck)
	{
		// player gets lucky takes a few but wins
		if (BestOfThree())
		{

			std::cout << "^^ Your enemy is your equal, you fight " << enemyName << " and get lucky \n   You feast on the still beating heart of your foe...\n   You gain health and luck. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
		else
		{

			std::cout << "^^ Your enemy is your equal, you fight " << enemyName << " and get lucky \n   However, you took a hit that is but a flesh wound...\n   Your health is tarnished but a bit. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
		Pause();
	}
	else if (HumanObj.GetHealth() < enemyHealth && HumanObj.GetLuck() >= enemyLuck)
	{
		// player gets lucky
		if (BestOfThree())
		{
			std::cout << "^^ Your enemy is healthier than you, you fight " << enemyName << " and get lucky \n   You feast on the still beating heart of your foe...\n   You gain health and luck. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
		else
		{
			std::cout << "^^ Your enemy is healthier than you, you fight " << enemyName << " and get lucky \n   However, you took a hit that is but a flesh wound...\n   Your health is tarnished but a bit. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
		Pause();
	}
	else
	{
		// player loses takes some damage
		std::cout << "^^ Your enemy is stronger, healthier and luckier than you.\n   You fight " << enemyName << " and you lose and flee... \n   You took several big hits...\n    Your health, strength are drained and you lost a lucky charm. \n";
		HumanObj.SetHealth(HumanObj.GetHealth() - 20);
		HumanObj.SetStrength(HumanObj.GetStrength() - 2);
		HumanObj.SetLuck(HumanObj.GetLuck() - 2);
		HumanStats(HumanObj);
		Pause();
	}
}

/*******************************************************************************************************
* BEST OF THREE - returns if a contest was successful or not
*******************************************************************************************************/
bool BestOfThree()
{
	int wins = 0;
	int loses = 0;
	int a = 0;
	int b = 0;
	int count = 0;
	// find out if 'a' wins
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
	// return result
	if (wins > loses)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*******************************************************************************************************
* HUMAN STATS - returns the vital statistics for the human player
*******************************************************************************************************/
void HumanStats(Human & HumanObj)
{
	std::cout << "\n   *------------------------------------------------------------*" << std::endl;
	std::cout << "   | Status for the human named * " << HumanObj.GetName() << " *" << std::endl;
	std::cout << "   *------------------------------------------------------------*" << std::endl;
	std::cout << "   |  - Health:       " << HumanObj.GetHealth() << std::endl;
	std::cout << "   |  - Strength:     " << HumanObj.GetStrength() << std::endl;
	std::cout << "   |  - Luck:         " << HumanObj.GetLuck() << std::endl;
	std::cout << "   |  - Intelligence: " << HumanObj.GetIntelligence() << std::endl;
	std::cout << "   *------------------------------------------------------------*" << std::endl;
}
/*******************************************************************************************************
* PAUSE - used to pause the game until player is ready
*******************************************************************************************************/
void Pause()
{
	const int userInputLimit= 20;
	char userInput[userInputLimit] = {};
	std::cout << "\n...\n";
	std::cin.getline(userInput, userInputLimit);
}

