#pragma once
#include "Location.h"
#include "Challenge.h"

class GeneralLocation :
	public Location
{
public:
	GeneralLocation(char * name, char * description, std::vector<int> ajacentLocations);
	virtual ~GeneralLocation();
private:
	void init();
};

