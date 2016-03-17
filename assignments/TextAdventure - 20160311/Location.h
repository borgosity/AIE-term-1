#pragma once
#include <string>
#include <vector>


class Location
{
public:
	Location();
	Location(const char * name, const char * description, int exitNum, int entryNum, std::vector<int> ajacentLocations);
	virtual ~Location();
	virtual const char* GetName();
	virtual const char* GetDescription();
	virtual std::vector<int> GetAjacentLoc();
	virtual std::vector<int> GetChallenges();
	virtual int GetPathChallenge(int desiredPath);
	virtual void SetChallenges(std::vector<int> challenges);
protected:
	char * m_name;
	char * m_description;
	int m_exitNum;
	int m_entryNum;
	std::vector<int> m_ajacentLocations = { 0,0,0,0 };
	std::vector<int> m_challenges = { 0,0,0,0 };
	void deleteString(const char * string);

};

