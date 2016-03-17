#include "GeneralLocation.h"



GeneralLocation::GeneralLocation(char * name, char * description, std::vector<int> ajacentLocations)
{
	m_name = nullptr;
	m_description = nullptr;

	deleteString(m_name);
	deleteString(m_description);
	init();

	m_name = new char[strlen(name) + 1];
	m_description = new char[strlen(description) + 1];
	strcpy(m_name, name);
	strcpy(m_description, description);
	m_ajacentLocations = ajacentLocations;
	
}


GeneralLocation::~GeneralLocation()
{
	//deleteString(m_name);
	//deleteString(m_description);
}

const char* GeneralLocation::GetName()
{
	return m_name;
}
const char* GeneralLocation::GetDescription()
{
	return m_description;
}
std::vector<int> GeneralLocation::GetAjacentLoc()
{
	return m_ajacentLocations;
}
std::vector<int> GeneralLocation::GetChallenges()
{
	return m_challenges;
}
int GeneralLocation::GetPathChallenge(int desiredPath)
{
	return m_challenges[desiredPath];
}
void GeneralLocation::SetChallenges(std::vector<int> challenges)
{
	m_challenges = challenges;
}

void GeneralLocation::init()
{
	m_entryNum = 4;
	m_exitNum = 3;
}
