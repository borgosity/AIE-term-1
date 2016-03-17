#pragma once
#include "Location.h"
#include "Challenge.h"
#include "Human.h"

void TestFinish();
void RandTest();
void UnitTests();
void TestInitaliseDestroy();
void TestChallenges(Location *Locations[]);
void TestCombat();
void TestCombat(Challenge * ChallengePtr, Human & HumanObj, Enemy *Enemies[]);
void TestBestOfThree();
void TestAddEnemyToChallenge();
void ChallengeTest();
void TestLoopCompare();