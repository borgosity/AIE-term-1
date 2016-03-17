#include <iostream>
#include "StringOO.h"
#include "Tests.h"

int main()
{
	// Intransiate strings to use in tests
	StringOO myString = "hello world";
	StringOO myString2 = "HELLO WORLD";
	StringOO myString3 = "hello ";
	StringOO myString4 = "world";
	StringOO myString5 = "hello world AIE";
	// Test results storage
	const int testNum = 12;
	bool results[testNum] = {};
	// Run Tests
	results[0] = Test0(myString);
	results[1] = Test1(myString);
	results[2] = Test2(myString);
	results[3] = Test3(myString3, myString4);
	results[4] = Test4(myString4, myString3);
	results[5] = Test5(myString);
	results[6] = Test6(myString2);
	results[7] = Test7(myString);
	results[8] = Test8(myString);
	results[9] = Test9(myString);
	results[10] = Test10(myString5);
	results[11] = Test11();
	// Write test results to file
	CalculateResults(results, testNum);
	// Finished
	std::cout << "\n\nFinished!" << std::endl;
	return 0;
}