#include "StartLocation.h"



StartLocation::StartLocation(char * name, char * description, std::vector<int> ajacentLocations)
{
	m_name = name;
	m_description = description;
	m_ajacentLocations = ajacentLocations;
	init();
}


StartLocation::~StartLocation()
{
	deleteString(m_name);
	deleteString(m_description);
}

void StartLocation::init()
{
	m_entryNum = 0;
	m_exitNum = 3;
}
