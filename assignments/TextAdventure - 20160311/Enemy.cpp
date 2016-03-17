#include "Enemy.h"



Enemy::Enemy()
{
}

Enemy::Enemy(int location, StringOO * name, int strength, int health, int luck)
{
	m_location = location;
	m_name = *name;
	m_strength = strength;
	m_health = health;
	m_luck = luck;
}

Enemy::Enemy(int location, const char * name, int strength, int health, int luck)
{
	m_location = location;
	m_name = name;
	m_strength = strength;
	m_health = health;
	m_luck = luck;
}

Enemy::~Enemy()
{
}
/*******************************************************************************************************
*
*******************************************************************************************************/
const char *  Enemy::GetName()
{
	return m_name.GetString();
}
/*******************************************************************************************************
*
*******************************************************************************************************/
int Enemy::GetStrength()
{
	return m_strength;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
int Enemy::GetHealth()
{
	return m_health;
}
/*******************************************************************************************************
*    
*******************************************************************************************************/
int Enemy::GetLuck()
{
	return m_luck;
}


