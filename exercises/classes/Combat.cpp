#include <iostream>
#include <stdlib.h>
#include "Combat.h"

using namespace std;

int SelectFighter(Zombie zombieArray[], int length)
{
	int selected = 0;
	selected = rand() % length;
	if (CheckHealth(zombieArray, selected))
	{
		return selected;
	}
	else
	{
		SelectFighter(zombieArray, length);
	}
}

bool CheckHealth(Zombie zombieArray[], int zombie)
{
	if (zombieArray[zombie].GetHealth() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Fight(Zombie zombieArray[], int zombie1, int zombie2)
{
	int damage = 0;
	int attacker = 0;
	int health = 0;
	
	attacker = rand() % 10;


	if (attacker <= 4)
	{
		damage = rand() % zombieArray[zombie1].GetStrength();
		health = zombieArray[zombie2].GetHealth() - damage;
		zombieArray[zombie2].SetHealth(health);
		return zombie1;
	}
	else
	{
		damage = rand() % zombieArray[zombie2].GetStrength();
		health = zombieArray[zombie1].GetHealth() - damage;
		zombieArray[zombie1].SetHealth(health);
		return zombie2;
	}
}

void PrintBattleResult(Zombie zombieArray[], int winner, int loser, int battleNum)
{
	cout << "The Battle " << battleNum << " winner was the:" ;
	cout << zombieArray[winner].GetOccupation() << endl;
	cout << " Strength = " << zombieArray[winner].GetStrength() << endl;
	cout << " Health = " << zombieArray[winner].GetHealth() << endl;

	cout << "The Battle " << battleNum << " loser was the:";
	cout << zombieArray[loser].GetOccupation() << endl;
	cout << " Strength = " << zombieArray[loser].GetStrength() << endl;
	cout << " Health = " << zombieArray[loser].GetHealth() << endl;
}

int CountTheDead(Zombie zombieArray[], int length)
{

}
