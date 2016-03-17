#include <iostream>
#include "Tests.h"
#include "StringOO.h"

#include "Human.h"
#include "Enemy.h"
#include "Question.h"
#include "GameFunctions.h"

void UnitTests()
{
	TestInitaliseDestroy();
	//ChallengeTest();
	//TestLoopCompare();
	//TestAddEnemyToChallenge();
	//TestCombat();
	//TestBestOfThree();
}

void TestChallenges(Location *Locations[])
{
	int locSize = 11;
	int vectorSize = 4;
	std::vector<int> challVector(vectorSize);

	for (int i = 0; i < locSize; i++)
	{
		challVector = Locations[i]->GetChallenges();
		for (int j = 0; j < vectorSize; j++)
		{
			std::cout << challVector[j] << std::endl;
		}
	}

}

void TestInitaliseDestroy()
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

	TestCombat()

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
void TestAddEnemyToChallenge()
{
	// challenges variables
	const int challengeNum = 15;
	Challenge *Challenges[challengeNum] = {};

	// enemy variables
	const int enemyNum = 5;
	Enemy * Enemies[enemyNum] = {};

	// initialise Enemies
	InitEnemies(Enemies, enemyNum);

	// initialise Challenges
	InitChallenges(Challenges);

	AddEnemyToChallenge(Enemies, Challenges, enemyNum, challengeNum);

	for (int i = 10; i < 15; i++)
	{
		std::cout << Challenges[i]->GetEnemy().GetName() << std::endl;
	}
}

void TestCombat()
{
	int humanLoc = 0;
	int enemyLoc = 2;
	StringOO name = "Barry";
	int strength = 10;
	int health = 100;
	int luck = 10;
	int intellegence = 10;

	Human * humanPtr = new Human(humanLoc, name, strength, health, luck, intellegence);
	const int enemyNum = 5;
	Enemy * Enemies[enemyNum] = {};
	InitEnemies(Enemies, enemyNum);
	//Enemy * enemyPtr = new Enemy(enemyLoc, name, strength, health, luck);

	for (int i = 0; i < enemyNum; i++)
	{
		Combat(*humanPtr, *Enemies[i]);
	}
}

void TestBestOfThree()
{
	for (int i = 0; i < 10; i++)
	{
		if (BestOfThree())
		{
			std::cout << "win \n";
		}
		else
		{
			std::cout << "loss \n";
		}
	}
}

void ChallengeTest()
{
	// human player variables
	int humanLoc = 0;
	StringOO name = "Barry";
	int strength = 10;
	int health = 100;
	int luck = 10;
	int intellegence = 10;
	int difficulty = 2;

	// initialise human
	Human Human(humanLoc, name, strength, health, luck, intellegence);
	Human.SetLocation(0);

	StringOO Question1 = ">> What day is Wednesday? \n  a) the third day \n  b) hump day \n  c) the day after Tuesday";
	StringOO Answer1 = "the day after Tuesday";
	Question Q1(Question1, Answer1, difficulty);

	//const int userInputLimit = 11;
	//char userInput[userInputLimit] = {};

	//std::cin.getline(userInput, userInputLimit);

	ApplyChallenge(Q1, Human);
}

void TestLoopCompare()
{
	StringOO str1 = "wednesday";
	const int userInputLimit = 25;
	char userInput[userInputLimit] = {};
	char * input = {};
	bool match = false;

	while (!match)
	{
		std::cin.getline(userInput, userInputLimit);
		if (str1.StringCompare(userInput))
		{
			match = true;
		}
	}
}