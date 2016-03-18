#pragma once
#include "Item.h"
#include <vector>
#include <memory>

class Inventory
{
public:
	Inventory();
	~Inventory();
	void AddItem(std::shared_ptr<Item> & item);
	void RemoveItem(std::shared_ptr<Item> & item);
	std::shared_ptr<Item> GetItem(std::shared_ptr<Item> & item) const;
	std::vector<std::shared_ptr<Item>> GetInventory() const;
	void PrintInventory() const;
	int GetWeight() const;
private:
	std::shared_ptr<Item> m_item;
	std::vector<std::shared_ptr<Item>> m_itemList;
};

