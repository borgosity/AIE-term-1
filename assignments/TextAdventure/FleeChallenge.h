#pragma once
#include "Challenge.h"
class FleeChallenge :
	public Challenge
{
public:
	FleeChallenge(char * description, int difficulty);
	virtual ~FleeChallenge();
};

