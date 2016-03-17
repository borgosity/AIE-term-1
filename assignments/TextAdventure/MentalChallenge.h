#pragma once
#include "Challenge.h"
class MentalChallenge :
	public Challenge
{
public:
	MentalChallenge(char * description, char * answer, int difficulty);
	virtual ~MentalChallenge();
private:
	char * m_answer;
};

