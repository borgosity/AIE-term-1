#include "Inventory.h"
#include <algorithm>
#include <iostream>



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::AddItem(std::shared_ptr<Item> & item)
{
	if (m_itemList.empty() || !item.get()->IsStackable())
	{
		m_itemList.push_back(item);
	}
	else
	{
		std::vector<std::shared_ptr<Item>>::iterator it = m_itemList.begin();
		bool found = false;
		while (it != m_itemList.end())
		{
			// check if items match
			if (item->GetName() == it->get()->GetName())
			{
				// if they match don't add item just increase stack count
				it->get()->SetStackCount(1);
				found = true;
				break;
			}
			else
			{
				it++;
			}
		}
		if (!found)
		{
			m_itemList.push_back(item);
		}
	}
}

void Inventory::RemoveItem(std::shared_ptr<Item> & item)
{
	if (item->IsStackable() && (item->GetStackCount() > 1))
	{
		auto it = std::find(m_itemList.begin(), m_itemList.end(), item);
		it->get()->SetStackCount(-1);
	}
	else
	{
		m_itemList.erase(std::remove(m_itemList.begin(), m_itemList.end(), item), m_itemList.end());
	}
		
}

std::shared_ptr<Item> Inventory::GetItem(std::shared_ptr<Item>& item) const
{
	auto it = std::find(m_itemList.begin(), m_itemList.end(), item);
	if (it != m_itemList.end())
	{
		return *it;
	}
	else
	{
		return m_item;
	}
}

std::vector<std::shared_ptr<Item>> Inventory::GetInventory() const
{
	return m_itemList;
}

void Inventory::PrintInventory() const
{
	auto it = m_itemList.begin();
	while (it != m_itemList.end())
	{
		std::cout << it->get()->GetName() << "\n";
		it++;
	}
}

int Inventory::GetWeight() const
{
	int total = 0;

	auto it = m_itemList.begin();
	while (it != m_itemList.end())
	{
		if (it->get()->IsStackable())
		{
			total += (it->get()->GetWeight()) * (it->get()->GetStackCount());
		}
		else 
		{
			total += it->get()->GetWeight();
		}
		it++;
	}

	return total;
}

