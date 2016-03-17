#pragma once
#include <string>


class Challenge
{
public:
	Challenge();
	Challenge(char * description, int difficulty);
	virtual ~Challenge();
	const char* GetDescription();
	const int GetDifficulty();
protected:
	char * m_description;
	int m_difficulty;
	void deleteString(const char * string);
};

