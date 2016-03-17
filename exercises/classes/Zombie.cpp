#include "Zombie.h"

using namespace std;

Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

int Zombie::GetStrength()
{
	return attackStrength;
}

void Zombie::SetStrength(int attackStrength)
{
	Zombie::attackStrength = attackStrength;
}

string Zombie::GetOccupation()
{
	return previousJob;
}

void Zombie::SetOccupation(string previousJob)
{
	Zombie::previousJob = previousJob;
}

int Zombie::GetHealth()
{
	return health;
}

void Zombie::SetHealth(int health)
{
	Zombie::health = health;
}

int Zombie::GetbattlesWon()
{
	return m_battlesWon;
}

void Zombie::SetbattlesWon(int battlesWon)
{
	m_battlesWon += battlesWon;
}

int Zombie::GetbattlesLost()
{
	return m_battlesLost;
}

void Zombie::SetbattlesLost(int battlesLost)
{
	m_battlesLost += battlesLost;
}
