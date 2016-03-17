#include "StringPlus.h"
#include <string>

/*
return int - length of string
return char - access a character at a certain index within the string class
return bool - compare if the string is the same as another string class
return string  - append one string to another
return string - prepend one string to another
return string - return the string as a basic constant C-style string (const char*)
return string - convert the string to a duplicate containing all lowercase letters
return string - convert the string to a duplicate containing all uppercase letters
return string - find a sub-string within the string class
return string - find a sub-string within the string class, starting from a certain index within the string
return string - replace a sub-string found within the string with a different sub-string
return string - set the string to an input C-style string
*/

StringPlus::StringPlus()
{
	m_userString = nullptr;
}

//StringPlus::StringPlus(char * userString)
//{
//	int length = strlen(userString) + 1;
//	char* m_userString = new char[length];
//	//m_userString = nullptr;
//	//SetString(userString);
//	strcpy(m_userString, userString);
//}


StringPlus::~StringPlus()
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
	}
}

char * StringPlus::GetString()
{
	return m_userString;
}

void StringPlus::SetString(const char * string0)
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
	}
	m_userString = new char[strlen(string0) + 1];
	strcpy(m_userString, string0);
}

int StringPlus::StringLength(char* string0)
{
	int count = 0;
	
	while (*string0 != 0)
	{
		count++;
	}
	return count;
}

char StringPlus::FindCharacter(char * string0)
{
	return 0;
}

bool StringPlus::StringCompare(char * string1, char * string2)
{
	return false;
}

char * StringPlus::StringAppend(char * string1, char * string2)
{
	return nullptr;
}

char * StringPlus::StringPrepend(char * string1, char * string2)
{
	return nullptr;
}

char * StringPlus::StringConstantCstyle(char * string0)
{
	return nullptr;
}

char * StringPlus::StringLowercase(char * string0)
{
	return nullptr;
}

char * StringPlus::StringUppercase(char * string0)
{
	return nullptr;
}

char * StringPlus::FindInString(char * string1, char * string2)
{
	return nullptr;
}

char * StringPlus::FindStringFromIndex(char * string0, int index)
{
	return nullptr;
}

char * StringPlus::SubStringReplace(char * string0, char * subString1, char * subString2)
{
	return nullptr;
}

char * StringPlus::StringInputCstyle(char * string0)
{
	return nullptr;
}
