#include <iostream>
#include <string>
#include "CharArrays.h"

using namespace std;

void CharArrayEx1()
{
	char fullName[80] = "";
	cout << "Enter your full name: ";
	cin.getline(fullName, 80);
	cout << "your name is: " << fullName << endl;

}

void GetLastName(char fullName[], char reverseName[])
{
	int c = 0;
	int length = strlen(fullName);

	while (fullName[c] <= ' ' && fullName[c] != 0)
	{
		c++;
	}
	while (fullName[c] != 0)
	{
		reverseName[c] = fullName[c];
	}
	cout << reverseName << endl;
}
void CharArrayEx2()
{
	char fullName[80] = "phill banks";
	char reverse[80] = "";
	int length = strlen(fullName) - 1;

	//for (int i = length; i >= 0; i--)
	//{
	//	for (int j = 0; j < length; j++)
	//	{
	//		if (i == length)
	//		{
	//			reverse[length] = fullName[i];
	//		}
	//		else
	//		{
	//			reverse[j] = fullName[i];
	//		}
	//		
	//	}
	//}
	GetLastName(fullName, reverse);
	cout << "your name is: " << reverse << endl;

}
