#pragma once
#include "Player.h"

class Enemy :
	public Player
{
public:
	Enemy();
	Enemy(int location, StringOO & name, int strength, int health, int luck);
	int GetStrength();
	int GetHealth();
	int GetLuck();
	virtual ~Enemy();
};

