#include "Player.h"



Player::Player()
{
}

Player::Player(int location, char * name)
{
	m_location = location;
	m_name = name;
}

Player::~Player()
{
	deleteString(m_name);
}

int Player::GetLocation()
{
	return m_location;
}

const char * Player::GetName()
{
	return m_name;
}

int Player::GetStrength()
{
	return m_strength;
}

int Player::GetHealth()
{
	return m_health;
}

int Player::Getluck()
{
	return m_health;
}

void Player::SetLocation(int location)
{
	m_location = location;
}

void Player::deleteString(const char * string)
{
	if (string != nullptr)
	{
		delete[] string;
		string = nullptr;
	}
}
