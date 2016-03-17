#pragma once
#include <string>
class Item
{
public:
	Item();
	Item(char * name, int weight, bool stackable);
	std::string GetName();
	int GetWeight();
	bool IsStackable();
	int GetStackCount();
	int SetStackCount();
	~Item();
private:
	std::string m_name;
	int m_weight;
	bool m_stackable;
	int m_stackCount;
};

