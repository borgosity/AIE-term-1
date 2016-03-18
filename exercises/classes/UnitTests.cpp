#include <iostream>
#include <memory>
#include "Item.h"
#include "Inventory.h"
#include "UnitTests.h"

void createItem()
{

	std::vector<std::shared_ptr<Item>> itemList;
	std::string hatName = "hat1";
	itemList.push_back(std::make_shared<Item>(hatName, 2, true));
	itemList.push_back( std::make_shared<Item>("milk", 5, false));
	itemList.push_back( std::make_shared<Item>("bread", 2, false));
	itemList.push_back( std::make_shared<Item>("blanket", 4, true));
	itemList.push_back( std::make_shared<Item>("jacket", 5, true));
	itemList.push_back( std::make_shared<Item>("bag", 3, false));

	for (std::vector<std::shared_ptr<Item>>::iterator it = itemList.begin(); it != itemList.end(); it++)
	{
		std::cout << it->get()->GetName() << '\n';
	}
		
}

void addToInventoryTest()
{
	auto itemList = std::make_shared<Inventory>();

	std::string hatName = "hat";
	std::string breadName = "bread";
	auto Hat = std::make_shared<Item>(hatName, 2, true);
	auto Bag = std::make_shared<Item>("bag", 3, false);

	itemList.get()->AddItem(std::make_shared<Item>("milk", 5, false));
	itemList.get()->AddItem(std::make_shared<Item>(breadName, 2, false));
	itemList.get()->AddItem(std::make_shared<Item>(hatName, 2, true));
	itemList.get()->AddItem(Hat);
	itemList.get()->AddItem(Bag);
	itemList.get()->AddItem(std::make_shared<Item>("blanket", 4, true));
	itemList.get()->AddItem(std::make_shared<Item>("jacket", 5, true));

	//std::vector<std::shared_ptr<Item>> tempList = itemList->GetInventory();

	//std::vector<std::shared_ptr<Item>>::iterator it = tempList.begin();
	//while (it != tempList.end())
	//{
	//	std::cout << it->get()->GetName() << "\n";
	//	it++;
	//}
	itemList->PrintInventory();
	std::cout << std::endl;

	itemList.get()->RemoveItem(Bag);
	//std::vector<std::shared_ptr<Item>> tempList2 = itemList->GetInventory();
	//std::vector<std::shared_ptr<Item>>::iterator it2 = tempList2.begin();
	//while (it2 != tempList2.end())
	//{
	//	std::cout << it2->get()->GetName() << "\n";
	//	it2++;
	//}
	itemList->PrintInventory();

	std::cout << "\n" << itemList->GetWeight() << std::endl;
}

void addToInventoryTest2()
{
	auto itemList = std::make_shared<Inventory>();
	std::shared_ptr<Inventory> itemList2;

	std::string hatName = "hat";
	std::string breadName = "bread";
	auto Hat = std::make_shared<Item>(hatName, 2, true);
	auto Bag = std::make_shared<Item>("bag", 3, false);

	itemList->AddItem(std::make_shared<Item>("milk", 5, false));
	itemList->AddItem(std::make_shared<Item>(breadName, 2, false));
	itemList->AddItem(std::make_shared<Item>(hatName, 2, true));
	itemList->AddItem(Hat);
	itemList->AddItem(Bag);
	itemList->AddItem(std::make_shared<Item>("blanket", 4, true));
	itemList->AddItem(std::make_shared<Item>("jacket", 5, true));

	itemList->PrintInventory();

	std::cout << std::endl;

	itemList->RemoveItem(Bag);

	itemList->PrintInventory();

	std::cout << "\n" << itemList->GetWeight() << std::endl;
}
