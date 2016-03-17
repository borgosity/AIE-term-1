#pragma once
#include "GeneralLocation.h"

class FinishLocation :
	public Location
{
public:
	FinishLocation(char * name, char * description, std::vector<int> ajacentLocations);
	virtual ~FinishLocation();
	const char* GetName();
	const char* GetDescription();
	std::vector<int> GetAjacentLoc();
	std::vector<int> GetChallenges();
	int GetPathChallenge(int desiredPath);
	void SetChallenges(std::vector<int> challenges);
private:
	void init();
};

