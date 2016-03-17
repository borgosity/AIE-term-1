#include <random>
#include <vector>
#include "GameFunctions.h"
#include "Initialisers.h"
#include "Question.h"
#include "Enemy.h"

/*******************************************************************************************************
*
*******************************************************************************************************/
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
	AllocateChallenges(Locations, locationNum);
	AddEnemyToChallenge(Enemies, Challenges, enemyNum, challengeNum);

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

			// determine the new location
			newLocation = PlayerMove(Human, humanMove, Locations[Human.GetLocation()]->GetAjacentLoc());

			// validate users move and if validate change their location
			if (ValidateMove(newLocation, prevLocation))
			{
				// set challenge user has to perform before progrogressing to the next room
				Human.SetChallenge(Locations[Human.GetLocation()]->GetPathChallenge(Human.GetHeading()));
				// challenge User
				ApplyChallenge(*Challenges[Human.GetChallenge()], Human);
				// move user to new location
				prevLocation = Human.GetLocation();
				Human.SetPrevHeading(Human.GetHeading());
				Human.SetLocation(newLocation);
				moveHuman = true;
				std::cout << "\n###===========================================================================##\n";
			}
			else
			{
				// invalid move try again
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
			HumanStats(Human);
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
*
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
*
*******************************************************************************************************/
bool ValidateMove(int newLocation, int prevLocation)
{
	if (newLocation == prevLocation)
	{
		std::cout << "!> Unfortunately that path was blocked behind you when you entered \n   You will have to select a different path =O\n" << std::endl;
		return false;
	}
	else if (newLocation == -1)
	{
		std::cout << "!> Please try using English to describe where you want to go :S \n  - move north \n  - move south \n  - move east \n  - move west\n" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void AllocateChallenges(Location & Locale, Human & Human)
{
	// Challenges exit allocation = { N, S , E, W }
	int vectorSize = 4;
	std::vector<int> challVector(vectorSize);

	for (int i = 0; i < vectorSize; i++)
	{
		challVector[i] = std::rand() % 16;
	}
	Locale.SetChallenges(challVector);
}
/*******************************************************************************************************
*
*******************************************************************************************************/
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
/*******************************************************************************************************
*
*******************************************************************************************************/
void ApplyChallenge(Challenge & challenge, Human & HumanObj)
{
	//metal challenge variables
	bool incorrect = true;
	int count = 0;
	const int userInputLimit = 25;
	char userInput[userInputLimit] = {};
	StringOO userAnswer;
	StringOO actualAnswer;
	// points
	int points = challenge.GetDifficulty() + HumanObj.GetLocation();

	if (challenge.GetType() == "flee")
	{
		std::cout << ">> To proceed in this direction we shall find out first if you can... \n";
		std::cout << challenge.GetDescription() << std::endl;
		if (BestOfThree())
		{
			std::cout << "+> Turns out yes, yes you can...you're free to pass! \n";
			HumanStats(HumanObj);
		}
		else
		{
			std::cout << "-> Nope, you can't as it turns out... \n   Someone had to come in and save you from yourself and further embarrassment...\n   Your fumbling has cost you health, strength, luck and intelligence." << std::endl;
			HumanObj.SetHealth(HumanObj.GetHealth() - points);
			HumanObj.SetStrength(HumanObj.GetStrength() - 2);
			HumanObj.SetLuck(HumanObj.GetLuck() - 2);
			HumanObj.SetIntelligence(HumanObj.GetIntelligence() - 1);
			HumanStats(HumanObj);
		}
	}
	else if (challenge.GetType() == "mental")
	{
		actualAnswer = challenge.GetAnswer();
		std::cout << ">> To proceed in this direction you must answer a question correctly... \n";
		std::cout << challenge.GetQuestion() << std::endl;
		while (incorrect)
		{
			std::cout << std::endl << "+ ";
			std::cin.getline(userInput, userInputLimit);
			userAnswer = userInput;
			if (userAnswer.StringCompare(actualAnswer) && count == 0)
			{
				std::cout << "+> Correct, please pass GO...Umm? but there is no $200 for you to collect... \n   At least you have your health ;-)" << std::endl;
				HumanStats(HumanObj);
				incorrect = false;
			}
			else if (userAnswer.StringCompare(actualAnswer) && count > 0)
			{
				std::cout << "-> Really? " << count << " guesses! Stop drinking the Coolade!, don't pass GO...! \n"; 
				points += count;
				std::cout << "   And give me " << points << " points of your best health and " << count << " of your intelligences... \n " << std::endl;
				HumanObj.SetHealth(HumanObj.GetHealth() - points);
				HumanObj.SetIntelligence(HumanObj.GetIntelligence() - count);
				HumanStats(HumanObj);
				incorrect = false;
			}
			else if (!userAnswer.StringCompare(actualAnswer) && count != 4)
			{
				std::cout << "   NOPE!! Try again...\n";
				count++;
			}
			else
			{
				std::cout << "-> STOP... I think thats enough don't you? \n";
				points += count;
				std::cout << "   And give me " << points << " points of your best health and " << count << " of your intelligences... \n " << std::endl;
				HumanObj.SetHealth(HumanObj.GetHealth() - points);
				HumanObj.SetIntelligence(HumanObj.GetIntelligence() - count);
				HumanStats(HumanObj);
				incorrect = false;
			}
		}

	}
	else if (challenge.GetType() == "physical")
	{
		std::cout << challenge.GetDescription() << std::endl;
		Combat(HumanObj, challenge.GetEnemy());
	}
	else
	{
		std::cout << "<?? Something went wrong, so your free to pass!! \n" << std::endl;
		HumanStats(HumanObj);
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void Combat(Human & HumanObj, Enemy & EnemyObj)
{
	if (HumanObj.GetStrength() >= EnemyObj.GetStrength() && HumanObj.GetLuck() >= EnemyObj.GetLuck())
	{
		// wins hands down
		if (BestOfThree())
		{
			std::cout << "^^ You are a formidable foe, you fight " << EnemyObj.GetName() << " and win easily \n   You feast on the still beating heart of your foe and gain health and strength. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetStrength(HumanObj.GetStrength() + 2);
			HumanStats(HumanObj);
		}
		else
		{
			std::cout << "^^ You are a formidable foe, you fight " << EnemyObj.GetName() << " and win easily \n   However, you took a hit that is but a flesh wound, your health is tarnished but a bit. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanStats(HumanObj);
		}

	}
	else if (HumanObj.GetHealth() >= EnemyObj.GetHealth() && HumanObj.GetLuck() >= EnemyObj.GetLuck())
	{
		// player gets lucky takes a few but wins
		if (BestOfThree())
		{

			std::cout << "^^ Your enemy is your equal, you fight " << EnemyObj.GetName() << " and get lucky \n   You feast on the still beating heart of your foe and gain health and luck. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
		else
		{

			std::cout << "^^ Your enemy is your equal, you fight " << EnemyObj.GetName() << " and get lucky \n   However, you took a hit that is but a flesh wound, your health is tarnished but a bit. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
	}
	else if (HumanObj.GetHealth() < EnemyObj.GetHealth() && HumanObj.GetLuck() >= EnemyObj.GetLuck())
	{
		// player gets lucky
		if (BestOfThree())
		{
			std::cout << "^^ Your enemy is healthier than you, you fight " << EnemyObj.GetName() << " and get lucky \n   You feast on the still beating heart of your foe and gain health and luck. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() + 10);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
		else
		{
			std::cout << "^^ Your enemy is healthier than you, you fight " << EnemyObj.GetName() << " and get lucky \n   However, you took a hit that is but a flesh wound, your health is tarnished but a bit. \n";
			HumanObj.SetHealth(HumanObj.GetHealth() - 5);
			HumanObj.SetLuck(HumanObj.GetLuck() + 2);
			HumanStats(HumanObj);
		}
	}
	else
	{
		// player loses takes some damage
		std::cout << "^^ Your enemy is stronger, healthier and luckier than you.\n   You fight " << EnemyObj.GetName() << " and you lose and flee... \n   You took a big hit that has sapped your health, strength and lost a lucky charm. \n";
		HumanObj.SetHealth(HumanObj.GetHealth() - 20);
		HumanObj.SetStrength(HumanObj.GetStrength() - 2);
		HumanObj.SetLuck(HumanObj.GetLuck() - 2);
		HumanStats(HumanObj);
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
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
/*******************************************************************************************************
*
*******************************************************************************************************/
void HumanStats(Human & HumanObj)
{
	std::cout << "\n*------------------------------------------------------------*" << std::endl;
	std::cout << "| Status for the human named * " << HumanObj.GetName() << " *" << std::endl;
	std::cout << "*------------------------------------------------------------*" << std::endl;
	std::cout << "|  - Health:       " << HumanObj.GetHealth() << std::endl;
	std::cout << "|  - Strength:     " << HumanObj.GetStrength() << std::endl;
	std::cout << "|  - Luck:         " << HumanObj.GetLuck() << std::endl;
	std::cout << "|  - Intelligence: " << HumanObj.GetIntelligence() << std::endl;
	std::cout << "*------------------------------------------------------------*" << std::endl;
}

