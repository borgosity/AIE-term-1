#include "FleeChallenge.h"



FleeChallenge::FleeChallenge(char * description, int difficulty)
{
	m_description = nullptr;
	deleteString(m_description);

	m_description = new char[strlen(description) + 1];
	strcpy(m_description, description);

	m_difficulty = difficulty;
}

FleeChallenge::~FleeChallenge()
{
}

const char * FleeChallenge::GetDescription()
{
	return m_description;
}

const int FleeChallenge::GetDifficulty()
{
	return m_difficulty;
}

const char * FleeChallenge::GetType()
{
	return type;
}

void FleeChallenge::SetDifficulty(int difficulty)
{
	m_difficulty = difficulty;
}


