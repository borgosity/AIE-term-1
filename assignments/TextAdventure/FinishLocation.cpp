#include "FinishLocation.h"



FinishLocation::FinishLocation(char * name, char * description, std::vector<int> ajacentLocations)
{
	m_name = name;
	m_description = description;
	m_ajacentLocations = ajacentLocations;
	init();
}


FinishLocation::~FinishLocation()
{
	deleteString(m_name);
	deleteString(m_description);
}

void FinishLocation::init()
{
	m_entryNum = 0;
	m_exitNum = 3;
}
