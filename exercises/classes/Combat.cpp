#include <iostream>
#include <stdlib.h>
#include "Combat.h"

using namespace std;

int SelectFighter(Zombie zombieArray[], int length)
{
	int selected = 0;
	selected = rand() % length;
	while(!CheckHealth(zombieArray, selected))
	{
		selected = rand() % length;
	}
	return selected;
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
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (zombieArray[i].GetHealth() <= 0)
		{
			count++;
		}
	}
	return count;
}
void Winner(Zombie zombieArray[], int length)
{
	int winner = 0;
	for (int i = 0; i < length; i++)
	{
		if (zombieArray[i].GetHealth() <= 0)
		{
			continue;
		}
		else
		{
			winner = i;
		}
	}
	cout << "The Final Suviver was the:";
	cout << zombieArray[winner].GetOccupation() << endl;
	cout << " Strength = " << zombieArray[winner].GetStrength() << endl;
	cout << " Health = " << zombieArray[winner].GetHealth() << endl;
	cout << " Battles Won = " << zombieArray[winner].GetbattlesWon() << endl;
	cout << " Battles Lost = " << zombieArray[winner].GetbattlesLost() << endl;
}
