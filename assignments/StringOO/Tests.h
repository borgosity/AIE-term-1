#pragma once
#include <iostream>
#include <fstream>
#include "StringOO.h"

// Unit Test Functions
bool Test0(StringOO& stringObj);
bool Test1(StringOO& stringObj);
bool Test2(StringOO& stringObj);
bool Test3(StringOO& stringObj1, StringOO& stringObj2);
bool Test4(StringOO& stringObj1, StringOO& stringObj2);
bool Test5(StringOO& stringObj);
bool Test6(StringOO& stringObj);
bool Test7(StringOO& stringObj);
bool Test8(StringOO& stringObj);
bool Test9(StringOO& stringObj);
bool Test10(StringOO& stringObj);
bool Test11();
// Print Test Results Function
void PrintOut(char * test, char * function, char * result);
void CalculateResults(bool * results, int testNum);
