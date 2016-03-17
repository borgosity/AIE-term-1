#pragma once
#include "Location.h"
class StartLocation :
	public Location
{
public:
	StartLocation(char * name,char * description, std::vector<int> ajacentLocations);
	virtual ~StartLocation();
private:
	void init();
};

