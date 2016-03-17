#include "Tests.h"



// Test -  int StringLength(char* string0);
bool Test0(StringPlus stringObj)
{
	int length = 0;
	char* string0 = stringObj.GetString();
	//strcpy(string0, stringObj.GetString());
	length = stringObj.StringLength(string0);
	
	if (length > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
		
}
// Test - char FindCharacter(char* string0);
bool Test1()
{
	return false;
}
// Test -  bool StringCompare(char* string1, char* string2);
bool Test2()
{
	return false;
}
// Test -  char* StringAppend(char* string1, char* string2);
bool Test3()
{
	return false;
}
// Test -  char* StringPrepend(char* string1, char* string2);
bool Test4()
{
	return false;
}
// Test -  char* StringConstantCstyle(char* string0);
bool Test5()
{
	return false;
}
// Test -  char* StringLowercase(char* string0);
bool Test6()
{
	return false;
}
// Test -  char* StringUppercase(char* string0);
bool Test7()
{
	return false;
}
// Test -  char* FindInString(char* string1, char* string2);
bool Test8()
{
	return false;
}
// Test -  char* FindStringFromIndex(char* string0, int index);
bool Test9()
{
	return false;
}
// Test -  char* SubStringReplace(char* string0, char* subString1, char* subString2);
bool Test10()
{
	return false;
}
// Test -  char* StringInputCstyle(char* string0);
bool Test11()
{
	return false;
}

