#include "PhysicalChallenge.h"



PhysicalChallenge::PhysicalChallenge(char * description, int difficulty)
{
}


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
