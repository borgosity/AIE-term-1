#include "StringOO.h"


/*******************************************************************************************************
*   Constructors and Destructors
*******************************************************************************************************/
StringOO::StringOO()
{
	m_userString = nullptr;
}

StringOO::StringOO(const char * string0)
{
	m_userString = nullptr;
	DeleteString();
	m_userString = new char[strlen(string0) + 1];
	strcpy(m_userString, string0);
}

StringOO::~StringOO()
{
	DeleteString();
}
/*******************************************************************************************************
*    Set String Function
*******************************************************************************************************/
void StringOO::SetString(const char * string0)
{
	DeleteString();
	m_userString = new char[strlen(string0) + 1];
	strcpy(m_userString, string0);
}
/*******************************************************************************************************
*    Get/Return String Function
*******************************************************************************************************/
char * StringOO::GetString()
{
	return m_userString;
}

/*******************************************************************************************************
*    Get/Return String Length Function
*******************************************************************************************************/
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
/*******************************************************************************************************
*    Get/Return Character At String Index
*******************************************************************************************************/
char StringOO::FindCharacter(int index)
{
	const char * string0 = m_userString;
	char character = -1;
	int length = StringLength();
	if (index < length)
	{
		character = string0[index];
	}
	// return -1 if index out of bounds
	return character;
}
/*******************************************************************************************************
*    Compare Two Strings and Return True if they Match
*******************************************************************************************************/
bool StringOO::StringCompare(StringOO& stringObj2)
{
	const char* pString1 = m_userString;
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
// String compare overload 
bool StringOO::StringCompare(const char * string2)
{
	const char* pString1 = m_userString;
	const char* pString2 = string2;

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
/*******************************************************************************************************
*    Append One String to Another String and Return the Result
*******************************************************************************************************/
char * StringOO::StringAppend(StringOO& stringObj2)
{
	int combinedLength = StringLength() + stringObj2.StringLength() + 1;
	char* string1 = m_userString;
	char* string2 = stringObj2.GetString();
	char* result = new char[combinedLength];
	strcpy(result, string1);
	strcat(result, string2);
	/*------------------------------------------------------------------------------------------
	|   if member variable is to be updated with new string memory cleanup wuould be required
	--------------------------------------------------------------------------------------------
	    SetString(result);
		delete[] result;
		result = nullptr;
		return m_userString;
	*/
	
	return result;
}
/*******************************************************************************************************
*    Prepend One String to Another String and Return the Result
*******************************************************************************************************/
char * StringOO::StringPrepend(StringOO& stringObj2)
{
	int combinedLength = StringLength() + stringObj2.StringLength() + 1;
	char* string1 = m_userString;
	char* string2 = stringObj2.GetString();
	char* result = new char[combinedLength];
	strcpy(result, string2);
	strcat(result, string1);
	/*------------------------------------------------------------------------------------------
	|   if member variable is to be updated with new string memory cleanup wuould be required
	--------------------------------------------------------------------------------------------
		SetString(result);
		delete[] result;
		result = nullptr;
		return m_userString;
	*/

	return result;
}
/*******************************************************************************************************
*    Return the String Object Member Variable as a C-style String
*******************************************************************************************************/
const char * StringOO::StringCstyle()
{
	const char* string0 = m_userString;
	int length = StringLength() + 1;
	char* result = new char[length];
	strcpy(result, string0);

	return result;
}
/*******************************************************************************************************
*    Return the String Object Member Variable in lowercase
*******************************************************************************************************/
char * StringOO::StringLowercase()
{
	char* pString0 = m_userString;
	int length = StringLength();
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
	/*------------------------------------------------------------------------------------------
	|   if member variable is to be updated with new string memory cleanup would be required
	--------------------------------------------------------------------------------------------
		SetString(result);
		delete[] result;
		result = nullptr;
		return m_userString;
	*/
	return result;
}
/*******************************************************************************************************
*    Return the String Object Member Variable in UPPERCASE
*******************************************************************************************************/
char * StringOO::StringUppercase()
{
	char* pString0 = m_userString;
	int length = StringLength();
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
	/*------------------------------------------------------------------------------------------
	|   if member variable is to be updated with new string memory cleanup is required
	--------------------------------------------------------------------------------------------
		SetString(result);
		delete[] result;
		result = nullptr;
		return m_userString;
	*/
	return result;
}
/*******************************************************************************************************
*    Find a Sub-string in the String Object Member Variable and Return True if it Exists
*******************************************************************************************************/
bool StringOO::FindInString(StringOO& stringObj2)
{
	const char* pString1 = m_userString;
	const char* pString2 = stringObj2.GetString();
	int str1Length = StringLength();
	int str2Length = stringObj2.StringLength();

	for (int i = 0; i < str1Length; i++)
	{
		if (*pString1 == *pString2)
		{
			for (int s = 0; s < str2Length; s++)
			{
				if (*pString1 == *pString2)
				{
					++pString1;
					++pString2;
					i++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			++pString1;
		}
	}
	// if all the substring characters were matched pString2 should have incremented to 0
	if (*pString2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
/*******************************************************************************************************
*    CREATED FOR USE IN REPLACE SUBSTRING FUNCTION - NOT REQUIRED BY ASSIGNMENT SPECS
*    Find a Sub-string in the String Object Member Variable and Return the Index of Where it Starts
*******************************************************************************************************/
int StringOO::FindSubStrIndex(StringOO& stringObj2)
{
	const char* pString1 = m_userString;
	const char* pString2 = stringObj2.GetString();
	int str1Length = StringLength();
	int str2Length = stringObj2.StringLength();
	int index = 0;

	for (int i = 0; i < str1Length; i++)
	{
		if (*pString1 == *pString2)
		{
			index = i;
			for (int s = 0; s < str2Length; s++)
			{
				if (*pString1 == *pString2)
				{
					++pString1;
					++pString2;
					i++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			++pString1;
		}
	}
	if (*pString2 == 0)
	{
		return index;
	}
	else
	{
		index = -1;
		return index;
	}
}
/*******************************************************************************************************
*    Find a Sub-string in the String Object Member Variable Given a Specific Index 
*    and Return True is it Exists
*******************************************************************************************************/
bool StringOO::FindStringFromIndex(StringOO& stringObj2, int index)
{
	const char* pString1 = m_userString;
	const char* pString2 = stringObj2.GetString();
	int str1Length = StringLength();
	int str2Length = stringObj2.StringLength();
	// increment pString1 to requested index
	pString1 = pString1 + index;
	// Check if supplied index is within bounds
	int length = StringLength();
	if (index < length)
	{
		for (int i = index; i < str1Length; i++)
		{
			if (*pString1 == *pString2)
			{
				for (int s = 0; s < str2Length; s++)
				{
					if (*pString1 == *pString2)
					{
						++pString1;
						++pString2;
						i++;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				++pString1;
			}
		}
		// if all the substring characters were matched pString2 should have incremented to 0
		if (*pString2 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
/*******************************************************************************************************
*    Find a Sub-string in the String Object Member Variable Given and Replace it with Another Sub-string
*    and Return the Result of the Replacement
*******************************************************************************************************/
char * StringOO::SubStringReplace(StringOO& subString1, StringOO& subString2)
{
	// first check to see if the substring exists
	if (FindInString(subString1))
	{
		// create pointers to strings
		const char* pString1 = m_userString;
		const char* pSubStr1 = subString1.GetString();
		const char* pSubStr2 = subString2.GetString();
		// get string lengths
		int strLength = StringLength();
		int oldStrLength = subString1.StringLength();
		int newStrLength = subString2.StringLength();
		// calculate result string length and create
		int resultLen = (strLength - oldStrLength) + newStrLength + 1;
		char* result = new char[resultLen];
		// find the difference between the old and new sub string
		int difference = 0;
		if (oldStrLength < newStrLength)
		{
			difference = oldStrLength - newStrLength;
		}
		else
		{
			difference = oldStrLength - newStrLength;
		}

		// get the index of where the sub string begins
		int index = FindSubStrIndex(subString1);
		// copy chars to new string
		for (int i = 0; i < resultLen; i++)
		{
			if (i < index)
			{
				//add all chars to result before the substring
				result[i] = pString1[i];
			}
			else if (i >= index && i < (index + newStrLength))
			{
				// add the replacement substring
				result[i] = pSubStr2[i - index];
			}
			else
			{
				// add any remaining chars from the original string after the substring
				result[i] = pString1[i + difference];
			}
		}
		/*------------------------------------------------------------------------------------------
		|   if member variable is to be updated with new string memory cleanup is required
		--------------------------------------------------------------------------------------------
			SetString(result);
			delete[] result;
			result = nullptr;
			return m_userString;
		*/
		return result;
	}
	else
	{
		// if the substring didn't exist return an error
		char* result = "Sub String Doesn't Exist";
		return result;
	}
	
}
/*******************************************************************************************************
*    Equals '=' operator overload to set member variable to new string 
*******************************************************************************************************/
void StringOO::operator= (const char* userString)
{
	DeleteString();
	m_userString = new char[strlen(userString) + 1];
	strcpy(m_userString, userString);
}
// Equals '=' operator overload to handle StringOO type strings
void StringOO::operator= (StringOO& userStringObj)
{
	const char* userString = userStringObj.GetString();
	DeleteString();
	m_userString = new char[strlen(userString) + 1];
	strcpy(m_userString, userString);
}

/*******************************************************************************************************
* Sadness maker
*******************************************************************************************************/
//StringOO::operator char*()
//{
//	return m_userString;
//}

/*******************************************************************************************************
* Member Function to Delete Member Variable and Set it to NULL
*******************************************************************************************************/
void StringOO::DeleteString()
{
	if (m_userString != nullptr)
	{
		delete[] m_userString;
		m_userString = nullptr;
	}
}


