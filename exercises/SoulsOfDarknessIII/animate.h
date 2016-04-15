#pragma once#pragma once
#include <vector>
#include <windows.h>    // Win32Api Header File

#include "UserAction.h"

void anitmation(std::vector<LPCWSTR> images);
void StartAnimation(UserAction & keypress, int width, int height);
void DummyAnimation(UserAction * keypress, int width, int height);