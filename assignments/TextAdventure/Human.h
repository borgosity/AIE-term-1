#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Human();
	Human(int location, const char * name, int strength, int health, int luck, int intellegence);
	virtual ~Human();
	int GetIntellegence();
protected:
	int m_intellegence;
private:
	void init();
};

