#pragma once
#include <string>
#include "StringOO.h"
#include "Enemy.h"


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
	virtual Enemy GetEnemy();
	virtual void SetDifficulty(int difficulty);
	virtual void SetEnemy(Enemy & EnemyObj);
protected:
	char * m_description;
	int m_difficulty;
	const char * m_type = nullptr;
	StringOO m_Question;
	StringOO m_Answer;
	Enemy m_Enemy;
	void deleteString(const char * string);
};

