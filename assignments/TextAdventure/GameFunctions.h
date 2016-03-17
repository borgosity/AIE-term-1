#pragma once
#include <iostream>

#include "StringOO.h"
#include "Location.h"	
#include "Challenge.h"

int PlayerMove(StringOO& move, std::vector<int> attachedLoc);
bool ValidateMove(int location1, int location2);
void AllocateChallenges(Location & location, Challenge & challenge, int blockedPath);

