#include "PhysicalChallenge.h"

PhysicalChallenge::PhysicalChallenge(char * description, int difficulty)
{
	m_description = nullptr;
	deleteString(m_description);

	m_description = new char[strlen(description) + 1];
	strcpy(m_description, description);

	m_difficulty = difficulty;
	m_type = "physical";
}

PhysicalChallenge::~PhysicalChallenge()
{
}
/*******************************************************************************************************
*
*******************************************************************************************************/
const char * PhysicalChallenge::GetDescription()
{
	return m_description;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
const int PhysicalChallenge::GetDifficulty()
{
	return m_difficulty;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
const char * PhysicalChallenge::GetType()
{
	return m_type;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
Enemy PhysicalChallenge::GetEnemy()
{
	return m_Enemy;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void PhysicalChallenge::SetDifficulty(int difficulty)
{
	m_difficulty = difficulty;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void PhysicalChallenge::SetEnemy(Enemy & EnemyObj)
{
	m_Enemy = EnemyObj;
}
