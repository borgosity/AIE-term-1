#include "Item.h"



Item::Item()
{
	m_name = "not given";
	m_weight = 0;
	m_stackable = false;
	m_stackCount = 0;
}

Item::Item(const char * name, int weight, bool stackable)
{
	m_name = name;
	m_weight = weight;
	m_stackable = stackable;
	m_stackCount = 0;
	if (m_stackable)
	{
		m_stackCount += 1;
	}
}

Item::Item(std::string name, int weight, bool stackable)
{
	m_name = name;
	m_weight = weight;
	m_stackable = stackable;
	m_stackCount = 0;
	if (m_stackable)
	{
		m_stackCount += 1;
	}
}

std::string Item::GetName() const
{
	return m_name;
}

int Item::GetWeight() const
{
	return m_weight;
}

bool Item::IsStackable() const
{
	return m_stackable;
}

int Item::GetStackCount() const
{
	return m_stackCount;
}

int Item::SetStackCount(int count)
{
	m_stackCount += count;
	return m_stackCount;
}


Item::~Item()
{
}
