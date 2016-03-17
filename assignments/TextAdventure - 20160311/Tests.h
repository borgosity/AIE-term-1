#pragma once
#include "Location.h"
#include "Challenge.h"
#include "Human.h"

void RandTest();
void UnitTests();
void TestInitaliseDestroy();
void TestChallenges(Location *Locations[]);
void TestCombat();
void TestCombat(Challenge * challenge, Human & HumanObj);
void TestBestOfThree();
void TestAddEnemyToChallenge();
void ChallengeTest();
void TestLoopCompare();