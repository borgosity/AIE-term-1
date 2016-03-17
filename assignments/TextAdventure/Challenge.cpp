#include "Challenge.h"


Challenge::Challenge()
{
	m_description = nullptr;
}

Challenge::Challenge(char * description, int difficulty)
{
	m_description = nullptr;
	deleteString(m_description);

	m_description = new char[strlen(description) + 1];
	strcpy(m_description, description);

	m_difficulty = difficulty;
}


Challenge::~Challenge()
{
	deleteString(m_description);
}

const char * Challenge::GetDescription()
{
	return m_description;
}

const int Challenge::GetDifficulty()
{
	return m_difficulty;
}

void Challenge::deleteString(const char * string)
{
	if (string != nullptr)
	{
		delete[] string;
		string = nullptr;
	}
}
