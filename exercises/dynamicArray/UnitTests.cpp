#include <iostream>
#include "UnitTests.h"
#include "DynamicArray.h"

void UnitTest_1()
{
	// create dynamic array
	DynamicArray<int> dyarr1(10);

	// add some elements to it
	dyarr1.AddToEnd(1);
	dyarr1.AddToEnd(2);
	dyarr1.AddToEnd(3);

	// assign to another dynamic array
	DynamicArray<int> dyarr2 = dyarr1;
	dyarr2[0] = 2;

	// copy dynamic array to another using the copy constructor
	DynamicArray<int> dyarr3(dyarr2);
	dyarr3[0] = 3;
	dyarr3.AddToEnd(4);

	DynamicArray<int> dyarr4(10);
	dyarr4.AddToEnd(4);
	dyarr4.AddToEnd(2);
	dyarr4.AddToEnd(3);
	dyarr4.AddToEnd(4);

	std::cout << "\nArray 1:\n";
	for (int i = 0; i < dyarr1.size(); i++)
	{
		std::cout << "   " << dyarr1[i] << "\n";
	}
	std::cout << "\nArray 2:\n";
	for (int i = 0; i < dyarr2.size(); i++)
	{
		std::cout << "   " << dyarr2[i] << "\n";
	}
	std::cout << "\nArray 3:\n";
	for (int i = 0; i < dyarr3.size(); i++)
	{
		std::cout << "   " << dyarr3[i] << "\n";
	}
	std::cout << "\nArray 4:\n";
	for (int i = 0; i < dyarr4.size(); i++)
	{
		std::cout << "   " << dyarr4[i] << "\n";
	}
}

void UnitTest_2()
{
	// add elements to the end of the array to force growing of array

	// remove elements from array

}

void UnitTest_3()
{
	// add element to the middle

	// add multiple elements to the middle
}

void UnitTest_4()
{
	// remove element from the middle

	// remove multiple elements in order from the middle

	// remove multiple elements unordered from the middle
}

void UnitTest_5()
{
}
