#pragma once
#include <iostream>

#include "StringOO.h"
#include "Location.h"	
#include "Challenge.h"
#include "Human.h"
#include "Initialisers.h"

void GameEngine();
int PlayerMove(Human & human, StringOO & move, std::vector<int> attachedLoc);
bool ValidateMove(int newLocation, int prevLocation);
void AllocateChallenges(Location & Locale, Human & Human);
void AllocateChallenges(Location *Locations[], int locSize);
void AllocateChallengesManually(Location *Locations[], int locSize);
void ApplyChallenge(Challenge * Challenge, Human & HumanObj);
void Combat(Human & HumanObj, Enemy * EnemyObj);
bool BestOfThree();
void HumanStats(Human & HumanObj);
void Pause();

