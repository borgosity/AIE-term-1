#pragma once
#include <iostream>
#include <string>

class StringOO
{
public:
	StringOO();
	StringOO(const char * string0);
	~StringOO();
	char * GetString();
	void SetString(const char* userString);
	// String Functions
	int StringLength();
	char FindCharacter(int index);
	bool StringCompare(StringOO& stringObj2);
	bool StringCompare(const char * string2);
	char* StringAppend(StringOO& stringObj2);
	char* StringPrepend(StringOO& stringObj2);
	const char* StringCstyle();
	char* StringLowercase();
	char* StringUppercase();
	bool FindInString(StringOO& stringObj2);
	int FindSubStrIndex(StringOO& stringObj2);
	bool FindStringFromIndex(StringOO& stringObj2, int index);
	char* SubStringReplace(StringOO& subString1, StringOO& subString2);
	// Set member variable using '=' operator
	void operator= (const char* userString);
	void operator= (StringOO& userStringObj);
	//operator char *();
private:
	// String member variable
	char* m_userString;
	// Member variable clenaup function
	void DeleteString();
};

