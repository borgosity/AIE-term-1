#include <iostream>
#include "StringPlus.h"
#include "Tests.h"

int main()
{
	//char myWord[20] = "someword";
	//char* myWordPtr = myWord;
	//StringPlus myString(myWord);
	StringPlus myString2;
	myString2.SetString("hello world");
	std::cout << myString2.GetString() << std::endl;

	if (Test0(myString2.GetString()))
	{
		std::cout << "Test 0" << "   Length   " << "   Successful" << std::endl;
	}
	else
	{
		std::cout << "Test 0" << "   Length   " << "   Successful" << std::endl;
	}
	return 0;
}