#pragma once
#include "Challenge.h"
class PhysicalChallenge :
	public Challenge
{
public:
	PhysicalChallenge(char * description, int difficulty);
	virtual ~PhysicalChallenge();
	virtual const char* GetDescription();
	virtual const int GetDifficulty();
	virtual const char* GetType();
	virtual void SetDifficulty(int difficulty);
private:
	const char * type = "physical";
};

