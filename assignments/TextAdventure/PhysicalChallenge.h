#pragma once
#include "Challenge.h"
class PhysicalChallenge :
	public Challenge
{
public:
	PhysicalChallenge(char * description, int difficulty);
	virtual ~PhysicalChallenge();
};

