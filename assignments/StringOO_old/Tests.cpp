#include "Tests.h"



// Test -  int StringLength(char* string0);
void Test0(StringOO& stringObj)
{
	int length = 0;
	length = stringObj.StringLength(stringObj);

	// expected string object legth is 11
	if (length > 0 && length == 11)
	{
		PrintOut("Test 0", "StringLength", "Successful");
	}
	else
	{
		PrintOut("Test 0", "StringLength", "Failed");
	}	
}
// Test - char FindCharacter(char* string0);
void Test1(StringOO& stringObj)
{
	int index = 6;
	char letter = ' ';
	letter = stringObj.FindCharacter(stringObj, index);

	if (letter == 'w')
	{
		PrintOut("Test 1", "FindCharacter", "Successful");
	}
	else
	{
		PrintOut("Test 1", "FindCharacter", "Failed");
	}
}
// Test -  bool StringCompare(char* string1, char* string2);
void Test2(StringOO& stringObj)
{
	bool result = false;
	bool result2 = true;
	StringOO string2 = "hello world";
	StringOO string3 = "hall0 werld";
	result = stringObj.StringCompare(stringObj, string2);
	result2 = stringObj.StringCompare(stringObj, string3);

	if (result && !result2)
	{
		PrintOut("Test 2", "StringCompare", "Successful");
	}
	else
	{
		PrintOut("Test 2", "StringCompare", "Failed");
	}
}
// Test -  char* StringAppend(char* string1, char* string2);
void Test3(StringOO& stringObj1, StringOO& stringObj2)
{
	StringOO resultStr = "hello world";
	StringOO appendedStr = stringObj1.StringAppend(stringObj1, stringObj2);

	if (stringObj1.StringCompare(appendedStr, resultStr))
	{
		PrintOut("Test 3", "StringAppend", "Successful");
	}
	else
	{
		PrintOut("Test 3", "StringAppend", "Failed");
	}
}
// Test -  char* StringPrepend(char* string1, char* string2);
void Test4(StringOO& stringObj1, StringOO& stringObj2)
{
	StringOO resultStr = "hello world";
	StringOO prependedStr = stringObj1.StringPrepend(stringObj1, stringObj2);

	if (stringObj1.StringCompare(prependedStr, resultStr))
	{
		PrintOut("Test 4", "StringPrepend", "Successful");
	}
	else
	{
		PrintOut("Test 4", "StringPrepend", "Failed");
	}
}
// Test -  char* StringCstyle(char* string0);
void Test5(StringOO& stringObj)
{
	const char * resultStr = "hello world";
	const char * cstyleStr = stringObj.StringCstyle(stringObj);

	if (strcmp(cstyleStr, resultStr) == 0)
	{
		PrintOut("Test 5", "StringCstyle", "Successful");
	}
	else
	{
		PrintOut("Test 5", "StringCstyle", "Failed");
	}
}
// Test -  char* StringLowercase(char* string0);
void Test6(StringOO& stringObj)
{
	const char * resultStr = "hello world";
	const char * lowercaseStr = stringObj.StringLowercase(stringObj);

	if (strcmp(lowercaseStr, resultStr) == 0)
	{
		PrintOut("Test 6", "StringLowercase", "Successful");
	}
	else
	{
		PrintOut("Test 6", "StringLowercase", "Failed");
	}
}
// Test -  char* StringUppercase(char* string0);
void Test7(StringOO& stringObj)
{
	const char * resultStr = "HELLO WORLD";
	const char * uppercaseStr = stringObj.StringUppercase(stringObj);

	if (strcmp(uppercaseStr, resultStr) == 0)
	{
		PrintOut("Test 6", "StringUppercase", "Successful");
	}
	else
	{
		PrintOut("Test 6", "StringUppercase", "Failed");
	}
}
// Test -  char* FindInString(char* string1, char* string2);
void Test8(StringOO& stringObj)
{
	StringOO stringObj2 = "world";
	bool result = stringObj.FindInString(stringObj, stringObj2);

	if (result)
	{
		PrintOut("Test 6", "StringUppercase", "Successful");
	}
	else
	{
		PrintOut("Test 6", "StringUppercase", "Failed");
	}
}
// Test -  char* FindStringFromIndex(char* string0, int index);
void Test9(StringOO& stringObj)
{
	
}
// Test -  char* SubStringReplace(char* string0, char* subString1, char* subString2);
void Test10(StringOO& stringObj)
{
	
}
// Test -  char* StringInputCstyle(char* string0);
void Test11(StringOO& stringObj)
{
	
}

void PrintOut(char * test, char * function, char * result)
{
	std::cout << test << "	" << function << "	" << result << std::endl;
}

