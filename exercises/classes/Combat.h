#pragma once
#include "Zombie.h"

int SelectFighter(Zombie zombieArray[], int length);
bool CheckHealth(Zombie zombieArray[], int zombie);
int Fight(Zombie zombieArray[], int zombie1, int zombie2 );
void PrintBattleResult(Zombie zombieArray[], int winner, int loser, int battleNum);
int CountTheDead(Zombie zombieArray[], int length);
void Winner(Zombie zombieArray[], int length);
