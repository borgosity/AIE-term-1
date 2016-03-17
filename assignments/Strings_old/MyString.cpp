#pragma once
#include "MyString.h"


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

int MyString::length(char string[])
{
	int result = 0;
	//for(auto i : string)
	result = strlen(string);

	return result;
}

char MyString::find(int index, char string[])
{
	char found;

	if (index > strlen(string))
	{
		char error;
		error = ' ';
		return error;
	}
	else
	{
		found = string[index];
		return found;
	}	
}

bool MyString::compare(char string_cmp[], char string[])
{
	if (strcmp(string, string_cmp))
	{
		return true;
	}
	else
	{
		return false;
	}
}
