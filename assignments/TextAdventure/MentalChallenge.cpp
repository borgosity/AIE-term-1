#include "MentalChallenge.h"



MentalChallenge::MentalChallenge(char * description, char * answer, int difficulty)
{
	m_description = nullptr;
	m_answer = nullptr;
	deleteString(m_description);
	deleteString(m_answer);

	m_description = new char[strlen(description) + 1];
	strcpy(m_description, description);

	m_answer = new char[strlen(answer) + 1];
	strcpy(m_answer, answer);

	m_difficulty = difficulty;
}

MentalChallenge::~MentalChallenge()
{
}
