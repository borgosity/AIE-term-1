#include "Human.h"



Human::Human()
{
}

Human::Human(int location, const char * name, int strength, int health, int luck, int intellegence)
{
	m_location = location;
	m_name = name;
	m_strength = strength;
	m_health = health;
	m_luck = luck;
	m_intellegence = intellegence;
}


Human::~Human()
{
}

int Human::GetIntellegence()
{
	return 0;
}

void Human::init()
{
	m_location = 0;
	m_name = "Player 1";
	m_health = 100;
	m_strength = 10;
	m_luck = 10;
	m_intellegence = 10;
}
