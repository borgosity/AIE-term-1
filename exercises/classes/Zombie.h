#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zombie
{
public:
	Zombie();
	~Zombie();
	int GetStrength();
	void SetStrength(int attackStrength);
	int GetHealth();
	void SetHealth(int health);
	int GetbattlesWon();
	void SetbattlesWon(int battlesWon);
	int GetbattlesLost();
	void SetbattlesLost(int battlesLost);
	string GetOccupation();
	void SetOccupation(string previousJob);

private:
	int attackStrength = 0;
	int health = 0;
	int m_battlesWon = 0;
	int m_battlesLost = 0;
	string previousJob = " ";
};

