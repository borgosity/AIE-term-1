#pragma once
#include <string>
#include "StringOO.h"


class Challenge
{
public:
	Challenge();
	Challenge(char * description, int difficulty);
	virtual ~Challenge();
	virtual const char* GetDescription();
	virtual const int GetDifficulty();
	virtual const char* GetType();
	virtual StringOO GetQuestion();
	virtual StringOO GetAnswer();
	virtual void SetDifficulty(int difficulty);
protected:
	char * m_description;
	int m_difficulty;
	const char * type = "default";
	StringOO m_Question;
	StringOO m_Answer;
	void deleteString(const char * string);
};

