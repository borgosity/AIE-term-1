#include <iostream>

#include "Monster.h"



/******************************************************************************
*******************************************************************************/
void doSomethingWithMonster(Monster monster)
{
}

/******************************************************************************
*******************************************************************************/
void main()
{
	// A monster on the stack
	Monster kingKong("King Kong");

	kingKong.gun().fire();

	doSomethingWithMonster(kingKong);

    std::cout << "\n\n\n";
}