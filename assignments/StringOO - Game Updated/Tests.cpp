#include "Tests.h"



/*******************************************************************************************************
*    Test 0 -  int StringLength();
*******************************************************************************************************/
bool Test0(StringOO& stringObj)
{
	int length = 0;
	length = stringObj.StringLength();

	// expected string object length is 11
	if (length > 0 && length == 11)
	{
		PrintOut("Test 0", "StringLength", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 0", "StringLength", "Failed");
		return false;
	}	
}
/*******************************************************************************************************
*    Test 1 - char FindCharacter(int index);
*******************************************************************************************************/
bool Test1(StringOO& stringObj)
{
	// Test 1 - inbounds index
	int index1 = 2;
	char result1 = stringObj.FindCharacter(index1);
	// Test 2 - space character
	int index2 = 5;
	char result2 = stringObj.FindCharacter(index2);
	// Test 3 - out of bounds index
	int index3 = 12;
	char result3 = stringObj.FindCharacter(index3);

	// Print Results
	if (result1 == 'l' && result2 == ' ' && result3 == -1)
	{
		PrintOut("Test 1", "FindCharacter", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 1", "FindCharacter", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 2 -  bool StringCompare(StringOO& stringObj2);
*******************************************************************************************************/
bool Test2(StringOO& stringObj)
{
	// Test 1 - match
	StringOO string2 = "hello world";
	bool result = stringObj.StringCompare(string2);
	// Tes 2 - don't match
	StringOO string3 = "hall0 werld";
	bool result2 = stringObj.StringCompare(string3);
	
	// Print Results
	if (result && !result2)
	{
		PrintOut("Test 2", "StringCompare", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 2", "StringCompare", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 3 -  char* StringAppend(StringOO& stringObj2);
*******************************************************************************************************/
bool Test3(StringOO& stringObj1, StringOO& stringObj2)
{
	StringOO expectedResult = "hello world";
	StringOO appendedStr = stringObj1.StringAppend(stringObj2);

	// Print Results
	if (appendedStr.StringCompare(expectedResult))
	{
		PrintOut("Test 3", "StringAppend", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 3", "StringAppend", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 4 -  char* StringPrepend(StringOO& stringObj2);
*******************************************************************************************************/
bool Test4(StringOO& stringObj1, StringOO& stringObj2)
{
	StringOO expectedResult = "hello world";
	StringOO prependedStr = stringObj1.StringPrepend(stringObj2);

	// Print Results
	if (prependedStr.StringCompare(expectedResult))
	{
		PrintOut("Test 4", "StringPrepend", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 4", "StringPrepend", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 5 -  const char* StringCstyle();
*******************************************************************************************************/
bool Test5(StringOO& stringObj)
{
	StringOO expectedResult = "hello world";
	StringOO cstyleStr = stringObj.StringCstyle();

	// Print Results
	if (expectedResult.StringCompare(cstyleStr))
	{
		PrintOut("Test 5", "StringCstyle", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 5", "StringCstyle", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 6 -  char* StringLowercase();
*******************************************************************************************************/
bool Test6(StringOO& stringObj)
{
	// Test 1 - uppercase to lowercase
	StringOO expectedResult = "hello world";
	StringOO lowercaseStr = stringObj.StringLowercase();
	// Test 2 - lowercase to lowercase
	StringOO  lowercaseStr2 = expectedResult.StringLowercase();

	// Print Results
	if (expectedResult.StringCompare(lowercaseStr) && expectedResult.StringCompare(lowercaseStr2))
	{
		PrintOut("Test 6", "StringLowercase", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 6", "StringLowercase", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 7 -  char* StringUppercase();
*******************************************************************************************************/
bool Test7(StringOO& stringObj)
{
	// Test 1 - lowercase to uppercase
	StringOO expectedResult = "HELLO WORLD";
	StringOO  uppercaseStr = stringObj.StringUppercase();
	// Test 2 - uppercase to uppercase
	StringOO  uppercaseStr2 = expectedResult.StringUppercase();

	// Print Results
	if (expectedResult.StringCompare(uppercaseStr) && expectedResult.StringCompare(uppercaseStr2))
	{
		PrintOut("Test 7", "StringUppercase", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 7", "StringUppercase", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 8 -  bool FindInString(StringOO& stringObj2);
*******************************************************************************************************/
bool Test8(StringOO& stringObj)
{
	// Test1 - look for existant sub string
	StringOO stringObj2 = "world";
	bool result = stringObj.FindInString(stringObj2);
	// Test2 - look for non existant sub string
	StringOO stringObj3 = "wrong";
	bool result2 = stringObj.FindInString(stringObj3);

	// Print Results
	if (result && !result2)
	{
		PrintOut("Test 8", "FindInString", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 8", "FindInString", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 9 -  bool FindStringFromIndex(StringOO& stringObj2, int index);
*******************************************************************************************************/
bool Test9(StringOO& stringObj)
{
	// Test 1 - vaild index and sub string in string
	int index = 6;
	StringOO stringObj2 = "world";
	bool result = stringObj.FindStringFromIndex(stringObj2, index);
	// Test 2 = valid index and sub string not in string
	index = 5;
	StringOO stringObj3 = "wrong";
	bool result2 = stringObj.FindStringFromIndex(stringObj3, index);
	// Test 3 - index out of bounds with valid string
	index = 15;
	bool result3 = stringObj.FindStringFromIndex(stringObj3, index);

	// Print Results
	if (result && !result2)
	{
		PrintOut("Test 9", "FindStringFromIndex", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 9", "FindStringFromIndex", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 10 -  char* SubStringReplace(StringOO& subString1, StringOO& subString2);
*******************************************************************************************************/
bool Test10(StringOO& stringObj)
{
	// Test 1 - replace world with galaxy
	StringOO substrObj1 = "world";
	StringOO substrObj2 = "galaxy";
	StringOO expectedResult = "hello galaxy AIE";
	StringOO result = stringObj.SubStringReplace(substrObj1, substrObj2);
	// Test 2 - replace non existent substring
	StringOO substrObj3 = "wrong";
	StringOO incorrectResult = "Sub String Doesn't Exist";
	StringOO result2 = stringObj.SubStringReplace(substrObj3, substrObj2);

	// Print Results
	if (expectedResult.StringCompare(result) && incorrectResult.StringCompare(result2))
	{
		PrintOut("Test 10", "SubStringReplace", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 10", "SubStringReplace", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Test 11-  char* StringInputCstyle(char* string0);
*******************************************************************************************************/
bool Test11()
{
	//Test 1 - copy input C-style string 
	StringOO myString1 = "hello world";
	// Test 2 - copy C-syle string by vairable name
	const char* cString = "hello world";
	StringOO myString2 = cString;
	// Test 3 - copy string from one StringOO type to another
	StringOO myString3 = "something";
	myString3 = myString1;

	// Print Results
	if (myString1.StringCompare(myString2) && myString1.StringCompare(myString3))
	{
		PrintOut("Test 11", "SubStringReplace", "Successful");
		return true;
	}
	else
	{
		PrintOut("Test 11", "SubStringReplace", "Failed");
		return false;
	}
}
/*******************************************************************************************************
*    Print Test Results Function
*******************************************************************************************************/
void PrintOut(char * test, char * function, char * result)
{
	// Variables
	std::ofstream testResults ("TestResults.txt", std::ofstream::out | std::ofstream::app);
	
	// Write to file
	if (testResults.is_open())
	{
		testResults << test << "	" << function << "	" << result << "\n";
		testResults.close();
	}
	else
	{
		std::cout << "Error opening file" << std::endl;
	}
	// Print to console
	std::cout << test << "	" << function << "	" << result << std::endl;
	
}
/*******************************************************************************************************
*    Calculate Results
*******************************************************************************************************/
void CalculateResults(bool results[], int testNum)
{
	// Variables
	float count = 0.00f;
	float percent = 0.00f;
	std::ofstream testResults("TestResults.txt", std::ofstream::out | std::ofstream::app);

	// count successful tests
	for (int i = 0; i < testNum; i++)
	{
		if (results[i] == 1)
		{
			count++;
		}
	}
	// concert count to percentage
	percent = 100 / (testNum / count);

	// Write to file
	if (testResults.is_open())
	{
		testResults << "Successful " << percent << "%\n\n";
		testResults.close();
	}
	else
	{
		std::cout << "Error opening file" << std::endl;
	}
	// Print to console
	std::cout << "Successful " << percent << "%" << std::endl;
}

