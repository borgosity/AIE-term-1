#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	MyString mstring;
	
	char input_str[256];
	int input_find;
	char str_compare[256];

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << "Please enter a string to find out the length" << endl;
	//	cin >> input;
	//	cout << "The length of your string is: " << mstring.length(input) << endl;
	//}

	cout << "Please enter a string to find out the length" << endl;
	cin >> input_str;
	cout << "The length of your string is: " << mstring.length(input_str) << endl;
	cout << "Enter a number to find the char at that point" << endl;
	cin >> input_find;
	input_find = input_find - 1;
	cout << "The char found at that index is: " << mstring.find(input_find, input_str) << endl;
	cout << "Please enter a string and I'll check if it matches" << endl;
	cin >> str_compare;
	if (str_compare) 
	{
		cout << "The second string matches the first string!!" << endl;
	}
	else
	{
		cout << "The second string does NOT match the first :(" << endl;
	}

	return 0;
}