#pragma once
#include <vector>
#include "StringOO.h"
#include "windows.h"
//location includes
#include "StartLocation.h"
#include "GeneralLocation.h"
#include "FinishLocation.h"

//player includes
#include "Human.h"
#include "Enemy.h"

// challenge includes
#include "FleeChallenge.h"
#include "Question.h"
#include "PhysicalChallenge.h"

void SetConsole();
void StartText(Human & HumanObj);
void InitLocations(Location *locations[]);
void InitChallenges(Challenge *challenge[]);
void InitEnemies(Enemy *Enemies[], const int enemyNum);
void InitHuman(Human human);
void AddEnemyToChallenge(Enemy * Enemies[], Challenge * Challenges[], int enemyNum, int challNum);

void DestroyLocations(Location *locations[], int length);
void DestroyChallenges(Challenge *challenge[], int length);
void DestroyEnemies(Enemy *Enemies[], int length);
