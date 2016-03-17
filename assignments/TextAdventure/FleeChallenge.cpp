#include "FleeChallenge.h"



FleeChallenge::FleeChallenge(char * description, int difficulty)
{
}


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
