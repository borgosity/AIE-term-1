#include <iostream>
#include "StringOO.h"
#include "Tests.h"

int main()
{
	StringOO myString = "hello world";
	StringOO myString2 = "HELLO WORLD";
	StringOO myString3 = "hello ";
	StringOO myString4 = "world";
	StringOO myString5 = "hello OO world";

	//myString = myString2;

	std::cout << myString.GetString() << std::endl;
	std::cout << myString2.GetString() << std::endl;

	
	Test0(myString);
	Test1(myString);
	Test2(myString);
	Test3(myString3, myString4);
	Test4(myString4, myString3);
	Test5(myString);
	Test6(myString2);
	Test7(myString);
	Test8(myString);

	std::cout << "\n\n Finished!" << std::endl;
	return 0;
}