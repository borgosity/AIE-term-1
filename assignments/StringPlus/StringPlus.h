#pragma once
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

class StringPlus
{
public:
	StringPlus();
	StringPlus(char* userString);
	~StringPlus();
	char* GetString();
	void SetString(const char* userString);
	int StringLength(char* string0);
	char FindCharacter(char* string0);
	bool StringCompare(char* string1, char* string2);
	char* StringAppend(char* string1, char* string2);
	char* StringPrepend(char* string1, char* string2);
	char* StringConstantCstyle(char* string0);
	char* StringLowercase(char* string0);
	char* StringUppercase(char* string0);
	char* FindInString(char* string1, char* string2);
	char* FindStringFromIndex(char* string0, int index);
	char* SubStringReplace(char* string0, char* subString1, char* subString2);
	char* StringInputCstyle(char* string0);
private:
	char* m_userString;

};

