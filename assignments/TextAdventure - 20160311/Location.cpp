#include "Location.h"



Location::Location()
{
	m_name = nullptr;
	m_description = nullptr;
}

Location::Location(const char * name,const char * description, int exitNum, int entryNum, std::vector<int> ajacentLocations)
{
	m_name = nullptr;
	m_description = nullptr;

	deleteString(m_name);
	deleteString(m_description);

	m_name = new char[strlen(name) + 1];
	m_description = new char[strlen(description) + 1];
	strcpy(m_name, name);
	strcpy(m_description, description);

	m_exitNum = exitNum;
	m_entryNum = entryNum;
	m_ajacentLocations = ajacentLocations;
}

Location::~Location()
{
	//deleteString(m_name);
	//deleteString(m_description);
}

const char * Location::GetName()
{
	return m_name;
}

const char * Location::GetDescription()
{
	return m_description;
}

std::vector<int> Location::GetAjacentLoc()
{
	return m_ajacentLocations;
}

std::vector<int> Location::GetChallenges()
{
	return m_challenges;
}

int Location::GetPathChallenge(int desiredPath)
{
	return m_challenges[desiredPath];
}

void Location::SetChallenges(std::vector<int> challenges)
{
	m_challenges = challenges;
}

void Location::deleteString(const char * string)
{
	if (string != nullptr)
	{
		delete[] string;
		string = nullptr;
	}
}

