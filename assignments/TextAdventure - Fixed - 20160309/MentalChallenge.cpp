#include "MentalChallenge.h"



MentalChallenge::MentalChallenge()
{
}

MentalChallenge::MentalChallenge(char * description, int difficulty)
{
	m_description = nullptr;
	deleteString(m_description);

	m_description = new char[strlen(description) + 1];
	strcpy(m_description, description);

	m_difficulty = difficulty;
}

MentalChallenge::~MentalChallenge()
{
}

const char * MentalChallenge::GetDescription()
{
	return m_description;
}

const int MentalChallenge::GetDifficulty()
{
	return m_difficulty;
}

const char * MentalChallenge::GetType()
{
	return type;
}

void MentalChallenge::SetDifficulty(int difficulty)
{
	m_difficulty = difficulty;
}
