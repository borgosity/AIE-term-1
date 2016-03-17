#include "PhysicalChallenge.h"

PhysicalChallenge::PhysicalChallenge(char * description, int difficulty)
{
	m_description = nullptr;
	deleteString(m_description);

	m_description = new char[strlen(description) + 1];
	strcpy(m_description, description);

	m_difficulty = difficulty;
}

PhysicalChallenge::~PhysicalChallenge()
{
}

const char * PhysicalChallenge::GetDescription()
{
	return m_description;
}

const int PhysicalChallenge::GetDifficulty()
{
	return m_difficulty;
}

const char * PhysicalChallenge::GetType()
{
	return type;
}

void PhysicalChallenge::SetDifficulty(int difficulty)
{
	m_difficulty = difficulty;
}
