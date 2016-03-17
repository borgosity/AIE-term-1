#pragma once
#include "Item.h"
#include <list>

class Inventory
{
public:
	Inventory();
	~Inventory();
	void AddItem(Item & item);
	void RemoveItem(Item & item);
	Item GetItem(Item & item);
	std::list<Item> GetInventory();
private:
	Item m_item;
	std::list<Item> m_Items;
};

