#include "Human.h"



Human::Human()
{
	//init();
}

Human::Human(int location, StringOO & name, int strength, int health, int luck, int intellegence)
{
	m_location = location;
	m_name = name;
	m_strength = strength;
	m_health = health;
	m_luck = luck;
	m_intellegence = intellegence;
	m_challenge = 0;
	m_heading = 0;
	m_prevHeading = 0;
}


Human::~Human()
{
}

int Human::GetChallenge()
{
	return m_challenge;
}

int Human::GetHeading()
{
	return m_heading;
}

int Human::GetPrevHeading()
{
	return m_prevHeading;
}

int Human::GetIntellegence()
{
	return m_challenge;
}

int Human::GetStrength()
{
	return m_strength;
}

int Human::GetHealth()
{
	return m_health;
}

int Human::GetLuck()
{
	return m_luck;
}

void Human::SetChallenge(int challenge)
{
	m_challenge = challenge;
}

void Human::SetHeading(int heading)
{
	m_heading = heading;
}

void Human::SetPrevHeading(int prevHeading)
{
	m_prevHeading = prevHeading;
}

void Human::SetHealth(int health)
{
	m_health = health;
}

void Human::SetStrength(int strength)
{
	m_strength = strength;
}

void Human::SetLuck(int luck)
{
	m_luck = luck;
}

void Human::init()
{
	m_location = 0;
	m_name = "Player 1";
	m_health = 100;
	m_strength = 10;
	m_luck = 10;
	m_intellegence = 10;
	m_challenge = 0;
	m_heading = 0;
	m_prevHeading = 0;
}
