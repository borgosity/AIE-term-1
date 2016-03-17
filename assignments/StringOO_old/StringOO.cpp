#include "StringOO.h"


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

StringOO::StringOO()
{
	m_userString = nullptr;
}

StringOO::StringOO(const char * string0)
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
	}
	m_userString = new char[strlen(string0) + 1];
	strcpy(m_userString, string0);
}

StringOO::~StringOO()
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
		//std::cout << "destructor called" << std::endl;
	}
}

void StringOO::operator=(const char* userString)
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
	}
	m_userString = new char[strlen(userString) + 1];
	strcpy(m_userString, userString);
}

char * StringOO::GetString()
{
	return m_userString;
}

void StringOO::SetString(const char * string0)
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
	}
	m_userString = new char[strlen(string0) + 1];
	strcpy(m_userString, string0);
}

int StringOO::StringLength(StringOO& stringObj)
{
	int count = 0;
	const char* pString0 = stringObj.GetString();

	while (*pString0 != 0)
	{
		++pString0;
		count++;
	}
	return count;
}

int StringOO::StringLength()
{
	int count = 0;
	const char* pString0 = m_userString;

	while (*pString0 != 0)
	{
		++pString0;
		count++;
	}
	return count;
}

char StringOO::FindCharacter(StringOO& stringObj, int index)
{
	const char * string0 = stringObj.GetString();
	char letter = string0[index];
	return letter;
}

bool StringOO::StringCompare(StringOO& stringObj1, StringOO& stringObj2)
{
	const char* pString1 = stringObj1.GetString();
	const char* pString2 = stringObj2.GetString();

	while ((*pString1 != 0) || (*pString2 != 0))
	{
		if (*pString1 == *pString2)
		{
			++pString1;
			++pString2;
		}
		else
		{
			return false;
		}		
	}
	return true;
}

char * StringOO::StringAppend(StringOO& stringObj1, StringOO& stringObj2)
{
	const char* pString1 = stringObj1.GetString();
	int combinedLength = StringLength(stringObj1) + StringLength(stringObj2) + 1;
	char* string1 = stringObj1.GetString();
	char* string2 = stringObj2.GetString();
	char* result = new char[combinedLength];
	strcpy(result, string1);
	strcat(result, string2);

	return result;
}

char * StringOO::StringPrepend(StringOO& stringObj1, StringOO& stringObj2)
{
	const char* pString1 = stringObj1.GetString();
	int combinedLength = StringLength(stringObj1) + StringLength(stringObj2) + 1;
	char* string1 = stringObj1.GetString();
	char* string2 = stringObj2.GetString();
	char* result = new char[combinedLength];
	strcpy(result, string2);
	strcat(result, string1);

	return result;
}

const char * StringOO::StringCstyle(StringOO& stringObj)
{
	const char* string0 = stringObj.GetString();
	int length = StringLength(stringObj) + 1;
	char* result = new char[length];
	strcpy(result, string0);
	return result;
}

char * StringOO::StringLowercase(StringOO& stringObj)
{
	char* pString0 = stringObj.GetString();
	int length = stringObj.StringLength(stringObj);
	int count = 0;
	char* result = new char[length];
	strcpy(result, pString0);
	
	for (int i = 0; i < length; i++)
	{
		if (result[i] > 64 && result[i] < 91)
		{
			result[i] = ((result[i] - 65) % 32) + 97;
		}	
	}
	return result;
}

char * StringOO::StringUppercase(StringOO& stringObj)
{
	char* pString0 = stringObj.GetString();
	int length = stringObj.StringLength(stringObj);
	int count = 0;
	char* result = new char[length];
	strcpy(result, pString0);

	for (int i = 0; i < length; i++)
	{
		if (result[i] > 96 && result[i] < 123)
		{
			result[i] = ((result[i] - 65) % 32) + 65;
		}
	}
	return result;
}

bool StringOO::FindInString(StringOO& stringObj1, StringOO& stringObj2)
{
	const char* pString1 = stringObj1.GetString();
	const char* pString2 = stringObj2.GetString();
	int length = stringObj2.StringLength();
	int count = 0;

	while ((*pString1 != 0) || (*pString2 != 0))
	{
		if (*pString1 == *pString2)
		{
			++pString1;
			++pString2;
			if (*pString1 == *pString2 && ((*pString1 != 0) || (*pString2 != 0)))
			{
				++pString1;
				++pString2;
			}
			else
			{
				--pString2;
			}
		}
		else
		{
			++pString1;
		}
	}
	return true;
}

char * StringOO::FindStringFromIndex(char * string0, int index)
{
	return nullptr;
}

char * StringOO::SubStringReplace(char * string0, char * subString1, char * subString2)
{
	return nullptr;
}

char * StringOO::StringInputCstyle(char * string0)
{
	return nullptr;
}
