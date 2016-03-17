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
