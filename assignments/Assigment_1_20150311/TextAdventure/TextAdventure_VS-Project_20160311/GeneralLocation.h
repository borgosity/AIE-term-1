#pragma once
#include "Location.h"
#include "Challenge.h"

class GeneralLocation :
	public Location
{
public:
	GeneralLocation(char * name, char * description, std::vector<int> ajacentLocations);
	virtual ~GeneralLocation();
	const char* GetName();
	const char* GetDescription();
	std::vector<int> GetAjacentLoc();
	std::vector<int> GetChallenges();
	int GetPathChallenge(int desiredPath);
	void SetChallenges(std::vector<int> challenges);
private:
	void init();
};

