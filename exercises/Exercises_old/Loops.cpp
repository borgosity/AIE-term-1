#include <iostream>

using namespace std;

// Exercise 1
void ForLoop()
{
	for (int i = 100; i != 0; i -= 2)
	{
		cout << i << endl;
	}
}
// Exercise 2
void ForMult()
{
	for (int i = 0; i != 100; i++)
	{
		if (((i % 3 == 0) && (i % 5 == 0)) && (i != 0))
		{
			cout << "FizzBuzz, cause of: " << i << endl;
		}
		else if ((i % 3 == 0) && (i != 0))
		{
			cout << "Fizz, cause of: " << i << endl;
		}
		else if ((i % 5 == 0) && (i != 0))
		{
			cout << "Buzz, cause of: " << i << endl;
		}
		else
		{
			cout << i << endl;
		}
		
	}
}
// Exercise 3
void Eula()
{
	int total = 0;
	for (int i = 0; i != 1000; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			total = i + total;
		}
	}
	cout << "The total of all the multiples of 3 and 5 is: " << total << endl;
}
// Exercise 4
void Exercise4()
{
	// Exercise 1
	cout << "-- Exercise 1 of Exercise 4" << endl;
	int i = 100;
	while ( i != 0)
	{
		cout << i << endl;
		i -= 2;
	}
	// Exercise 2
	cout << "-- Exercise 2 of Exercise 4" << endl;
	i = 0;
	while (i != 100)
	{
		if (((i % 3 == 0) && (i % 5 == 0)) && (i != 0))
		{
			cout << "FizzBuzz, cause of: " << i << endl;
		}
		else if ((i % 3 == 0) && (i != 0))
		{
			cout << "Fizz, cause of: " << i << endl;
		}
		else if ((i % 5 == 0) && (i != 0))
		{
			cout << "Buzz, cause of: " << i << endl;
		}
		else
		{
			cout << i << endl;
		}
		i++;
	}
	// Exercise 3
	cout << "-- Exercise 3 of Exercise 4" << endl;
	int total = 0; 
	i = 0;
	for (int i = 0; i != 1000; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			total = i + total;
		}
	}
	cout << "The total of all the multiples of 3 and 5 is: " << total << endl;
}
//int main()
//{
//	//ForLoop(); //exercise 1
//	//ForMult(); //exercise 2
//	//Eula(); //exercise 3
//	Exercise4();
//	return 0;
//}

