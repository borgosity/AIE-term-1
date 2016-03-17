#pragma once
#include "Location.h"
class FinishLocation :
	public Location
{
public:
	FinishLocation(char * name, char * description, std::vector<int> ajacentLocations);
	virtual ~FinishLocation();
private:
	void init();
};

