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
	//deleteString(m_name);
	//deleteString(m_description);
}

const char* StartLocation::GetName()
{
	return m_name;
}
const char* StartLocation::GetDescription()
{
	return m_description;
}
std::vector<int> StartLocation::GetAjacentLoc()
{
	return m_ajacentLocations;
}
std::vector<int> StartLocation::GetChallenges()
{
	return m_challenges;
}
int StartLocation::GetPathChallenge(int desiredPath)
{
	return m_challenges[desiredPath];
}
void StartLocation::SetChallenges(std::vector<int> challenges)
{
	m_challenges = challenges;
}
void StartLocation::init()
{
	m_entryNum = 0;
	m_exitNum = 3;
}
