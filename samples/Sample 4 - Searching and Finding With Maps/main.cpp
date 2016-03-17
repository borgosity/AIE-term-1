#include <iostream>
#include <Windows.h> // INclude this to use the Windows API
#include <vector>	 // Include this to use std::vector
#include <string>	 // Include this to use std::string
#include <map>		 // Include this to use std::map



int g_startTime = ::GetTickCount();

/******************************************************************************
Returns the time elapsed since the program started (in seconds)
*******************************************************************************/
double elapsedTime()
{
	return (double)( ::GetTickCount() - g_startTime ) / 1000.0;
}

/******************************************************************************
Resets the time counter back to zero
*******************************************************************************/
void restartTime()
{
	g_startTime = ::GetTickCount();
}

/******************************************************************************
Creates a 20-character string filled with randomly-generated alphabetic characters
*******************************************************************************/
std::string randomString()
{
	std::string s;

	s.resize(20);
	for (size_t i = 0; i < s.length(); i++)
	{
		s[i] = 'a' + (rand() % 26);
	}

	return s;
}

/******************************************************************************
*******************************************************************************/
void main()
{
	std::system("cls");

	std::cout << "Preparing...\n\n";

	int i;

	// An array of strings
	int numStrings = 100000;
	std::vector< std::string > strings;

	// Fill the array with 'numStrings' randomly-generated strings.
	strings.resize(numStrings);
	for (i = 0; i < numStrings; i++)
	{
		strings[i] = randomString();
	}

	// Output timing results to the console
	std::cout << std::fixed;
	std::cout << "Array filled with " << numStrings << " strings in = " << elapsedTime() << " seconds\n\n";
	std::system("pause");

	restartTime();

	// Define a new type 'MyMap' around a std::map. This will simplify the syntax considerably.
	typedef std::map< std::string, int > MyMap;

	// Declare a MyMap variable. We can now insert stuff into the map.
	MyMap myMap;

	// Insert 'numStrings' randomly-generated strings into the map'. This is a slower operation than std::vector
	for (i = 0; i < numStrings; i++)
	{
		myMap.insert(MyMap::value_type(randomString(), 0));
	}

	// Output timing results to the console
	std::cout << "\nMap filled with " << numStrings << " strings in = " << elapsedTime() << " seconds\n\n";
	std::system("pause");
	restartTime();

	// Seearch for an item in the array. We search for something that we know won't be in the
	// array so we get a worst-case result.
	for (i = 0; i < numStrings; i++)
	{
		if (strings[i] == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa" )
		{
			break;
		}
	}

	// Output timing results to the console
	std::cout << "\n\nLinear search took = " << elapsedTime() << " seconds\n\n";
	std::system("pause");
	restartTime();

	// Search for an item in the map. Again we search for a non-existent item to force
	// a worst-case result.
	MyMap::const_iterator it;
	for (i = 0; i < 1000; i++)
	{
		it = myMap.find("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	}
	if (it != myMap.end())
	{
		std::cout << "\nString found!\n\n";
	}
	else
	{
		std::cout << "\nString not found!\n\n";
	}

	// Output timing results to the console
	std::cout << "Map search took = " << elapsedTime() / 1000.0 << " seconds\n\n";

	std::cout << "\n\nDone\n\n";
}