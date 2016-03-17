#pragma once
#include "GeneralLocation.h"

class StartLocation :
	public Location
{
public:
	StartLocation(char * name,char * description, std::vector<int> ajacentLocations);
	virtual ~StartLocation();
	const char* GetName();
	const char* GetDescription();
	std::vector<int> GetAjacentLoc();
	std::vector<int> GetChallenges();
	int GetPathChallenge(int desiredPath);
	void SetChallenges(std::vector<int> challenges);
private:
	void init();
};

