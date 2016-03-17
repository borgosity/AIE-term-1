#pragma once
#include "Challenge.h"
class MentalChallenge :
	public Challenge
{
public:
	MentalChallenge();
	MentalChallenge(char * description, int difficulty);
	virtual ~MentalChallenge();
	virtual const char* GetDescription();
	virtual const int GetDifficulty();
	virtual const char* GetType();
	virtual void SetDifficulty(int difficulty);
	virtual StringOO GetQuestion();
	virtual StringOO GetAnswer();
};

