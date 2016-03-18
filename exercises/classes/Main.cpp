#include <iostream>
#include <string>
#include "Zombie.h"
#include "Combat.h"
#include "UnitTests.h"

using namespace std;

string Occupations(int selector)
{
	string jobs[] = { "baker","cook","lawyer","bricklayer","programmer","cleaner","dancer","driver","waiter","milkman" };
	string job = jobs[selector];
	return job;
}
void GameLoop()
{
	const int zombieNum = 10;
	Zombie zombieArray[zombieNum];
	string deadZombies[zombieNum];
	int zombie1 = 0;
	int zombie2 = 0;
	int combatResult = 0;
	int loser = 0;
	int battleNum = 0;
	bool finished = false;

	for (int i = 0; i < zombieNum; i++)
	{
		Zombie zombie;
		zombie.SetHealth(100);
		zombie.SetStrength(rand() % 100 + 30);
		zombie.SetOccupation(Occupations(i));
		zombieArray[i] = zombie;

		cout << " Occupation = " << zombieArray[i].GetOccupation() << endl;
		cout << " Strength = " << zombieArray[i].GetStrength() << endl;
		cout << " Health = " << zombieArray[i].GetHealth() << endl;
		cout << "========================" << endl;
	}
	while (!finished)
	{
		zombie1 = SelectFighter(zombieArray, zombieNum);
		zombie2 = SelectFighter(zombieArray, zombieNum);
		if (zombie1 == zombie2)
		{
			while (zombie1 == zombie2)
			{
				zombie2 = SelectFighter(zombieArray, zombieNum);
			}
		}
		combatResult = Fight(zombieArray, zombie1, zombie2);
		battleNum++;
		if (combatResult == zombie1)
		{
			zombieArray[zombie1].SetbattlesWon(1);
			zombieArray[zombie2].SetbattlesLost(1);
			loser = zombie2;
		}
		else
		{
			zombieArray[zombie2].SetbattlesWon(1);
			zombieArray[zombie1].SetbattlesLost(1);
			loser = zombie1;
		}
		PrintBattleResult(zombieArray, combatResult, loser, battleNum);
		if (CountTheDead(zombieArray, zombieNum) < 9)
		{
			finished = false;
		}
		else
		{
			finished = true;
			Winner(zombieArray, zombieNum);
		}

	}

}

int main()
{
	//int again = 0;

	//while (again == 0)
	//{
	//	GameLoop();
	//	cin >> again;
	//}
	//createItem();
	
	//addToInventoryTest();
	
	addToInventoryTest2();

	std::cout << "\n\nfinished!!\n";
}