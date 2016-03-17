#pragma once
#include <string>
#include <vector>


class Location
{
public:
	Location();
	Location(const char * name, const char * description, int exitNum, int entryNum, std::vector<int> ajacentLocations);
	virtual ~Location();
	const char* GetName();
	const char* GetDescription();
	std::vector<int> GetAjacentLoc();
	std::vector<int> GetChallenges();
	void SetChallenges(std::vector<int> challenges);
protected:
	char * m_name;
	char * m_description;
	int m_exitNum;
	int m_entryNum;
	std::vector<int> m_ajacentLocations = {};
	std::vector<int> m_challenges = {};
	void deleteString(const char * string);

};

