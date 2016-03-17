#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Human();
	Human(int location, StringOO & name, int strength, int health, int luck, int intellegence);
	virtual ~Human();
	int GetChallenge();
	int GetHeading();
	int GetPrevHeading();
	int GetIntelligence();
	int GetStrength();
	int GetHealth();
	int GetLuck();
	void SetChallenge(int challenge);
	void SetHeading(int heading);
	void SetPrevHeading(int prevHeading);
	void SetHealth(int health);
	void SetStrength(int strength);
	void SetLuck(int luck);
	void SetIntelligence(int intelligence);
protected:
	int m_intellegence;
	int m_challenge;
	int m_heading;
	int m_prevHeading;
private:
	void init();
};

