#include "Recursion.h"
#include <iostream>

using namespace std;

// Exercise 1
void Fibonacci(int current, int next)
{
	int temp = (current + next);

	cout << next << endl;
	if (next < 100)
	{
		Fibonacci(next, temp);
	}
	else
	{
		cout << "Done !!" << endl;
	}
}


void RecursionEx1()
{
	int startNum = 0;
	int nextNum = 1;
	Fibonacci(startNum, nextNum);
}

// Exercise 2
void PowerOf(int x, int y, int count, int last)
{
	if (last == 0)
	{
		last = x;
	}
	if (count != y)
	{
		last = last * x;
		count++;
		PowerOf(x, y, count, last);
	}
	else
	{
		cout << last << endl;
	}
	
}

void RecursionEx2()
{
	int number = 2;
	int power = 5;
	int count = 1;
	int lastNum = 0;
	PowerOf(number, power, count, lastNum);
}


// Exercise 3 Challenge
void RecursionEx3()
{
}
