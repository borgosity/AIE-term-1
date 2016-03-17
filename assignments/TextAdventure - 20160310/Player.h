#pragma once
#include "StringOO.h"

class Player
{
public:
	Player();
	Player(int location, StringOO & name);
	virtual ~Player();
	virtual int GetLocation();
	//virtual const char* GetName();
	virtual StringOO GetName();
	virtual int GetStrength();
	virtual int GetHealth();
	virtual int GetLuck();
	virtual void SetLocation(int location);
protected:
	int m_location;
	StringOO m_name;
	int m_strength;
	int m_health;
	int m_luck;
private:
	void deleteString(const char * string);
};

