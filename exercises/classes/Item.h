#pragma once
#include <string>
class Item
{
public:
	Item();
	Item(const char * name, int weight, bool stackable);
	Item(std::string name, int weight, bool stackable);
	std::string GetName() const;
	int GetWeight() const;
	bool IsStackable() const;
	int GetStackCount() const;
	int SetStackCount(int count);
	~Item();
private:
	std::string m_name;
	int m_weight;
	bool m_stackable;
	int m_stackCount;
};

