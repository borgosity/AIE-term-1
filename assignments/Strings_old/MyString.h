#pragma once
#include "string.h"


class MyString
{
private:
	int result;
	char found;
public:
	int length(char string[]);
	char find(int index, char string[]);
	bool compare(char string_cmp[], char string[]);
};


