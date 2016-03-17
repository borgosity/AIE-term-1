#pragma once
#include "Challenge.h"
#include "Enemy.h"

class PhysicalChallenge :
	public Challenge
{
public:
	PhysicalChallenge(StringOO description, int difficulty);
	virtual ~PhysicalChallenge();
	virtual const char* GetDescription();
	virtual const int GetDifficulty();
	virtual const char* GetType();
	virtual int GetEnemy();
	virtual void SetDifficulty(int difficulty);
	virtual void SetEnemy(int enemy);
};

