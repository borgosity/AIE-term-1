#include "GeneralLocation.h"



GeneralLocation::GeneralLocation(char * name, char * description, std::vector<int> ajacentLocations)
{
	m_name = nullptr;
	m_description = nullptr;

	deleteString(m_name);
	deleteString(m_description);

	m_name = new char[strlen(name) + 1];
	m_description = new char[strlen(description) + 1];
	strcpy(m_name, name);
	strcpy(m_description, description);

	m_ajacentLocations = ajacentLocations;
	init();
}


GeneralLocation::~GeneralLocation()
{
	deleteString(m_name);
	deleteString(m_description);
}

void GeneralLocation::init()
{
	m_entryNum = 4;
	m_exitNum = 3;
}
