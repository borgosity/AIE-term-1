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
	string GetOccupation();
	void SetOccupation(string previousJob);

private:
	int attackStrength = 0;
	int health = 0;
	string previousJob = " ";
};

