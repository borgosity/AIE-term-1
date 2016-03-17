#pragma once
#include "Challenge.h"
class FleeChallenge :
	public Challenge
{
public:
	FleeChallenge(char * description, int difficulty);
	virtual ~FleeChallenge();
	virtual const char* GetDescription();
	virtual const int GetDifficulty();
	virtual const char* GetType();
	virtual void SetDifficulty(int difficulty);
};

