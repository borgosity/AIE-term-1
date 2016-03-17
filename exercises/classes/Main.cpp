#include <iostream>
#include <string>
#include "Zombie.h"
#include "Combat.h"

using namespace std;

string Occupations(int selector)
{
	string jobs[] = { "baker","cook","lawyer","bricklayer","programmer","cleaner","dancer","driver","waiter","milkman" };
	string job = jobs[selector];
	return job;
}

int main()
{
	const int zombieNum = 10;
	Zombie zombieArray[zombieNum];
	string deadZombies[zombieNum];
	int zombie1 = 0;
	int zombie2 = 0;
	int combatResult = 0;
	int loser = 0;
	int battleNum = 0;
	bool finished = true;

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
	while (finished)
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
			loser = zombie2;
		}
		else
		{
			loser = zombie1;
		}
		PrintBattleResult(zombieArray, combatResult, loser, battleNum);
		finished = false;
	}
}