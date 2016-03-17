#pragma once
#include <string>
#include "StringOO.h"
#include "Enemy.h"


class Challenge
{
public:
	Challenge();
	Challenge(StringOO description, int difficulty);
	virtual ~Challenge();
	virtual const char* GetDescription();
	virtual const int GetDifficulty();
	virtual const char* GetType();
	virtual const char *  GetQuestion();
	virtual const char *  GetAnswer();
	virtual int GetEnemy();
	virtual void SetDifficulty(int difficulty);
	virtual void SetEnemy(int enemy);
protected:
	StringOO m_description;
	int m_difficulty;
	const char * m_type = nullptr;
	StringOO m_Question;
	StringOO m_Answer;
	int m_enemy;
	void deleteString(const char * string);
};

