#include <iostream>
#include "Tests.h"
#include "StringOO.h"

#include "Human.h"
#include "Enemy.h"
#include "Question.h"
#include "GameFunctions.h"

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
	InitEnemies(Enemies);
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

	// initialise human
	Human Human(humanLoc, name, strength, health, luck, intellegence);
	Human.SetLocation(0);

	StringOO Question1 = ">> What day is Wednesday? \n  a) the third day \n  b) hump day \n  c) the day after Tuesday";
	StringOO Answer1 = "the day after Tuesday";
	Question Q1(Question1, Answer1);
	Q1.SetDifficulty(2);

	//const int userInputLimit = 11;
	//char userInput[userInputLimit] = {};

	//std::cin.getline(userInput, userInputLimit);

	ApplyChallenge(Q1, Human);
}
