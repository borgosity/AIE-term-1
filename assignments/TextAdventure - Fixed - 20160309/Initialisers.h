#pragma once
#include <vector>
#include "StringOO.h"
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

void InitLocations(Location *locations[]);
void InitChallenges(Challenge *challenge[]);
void InitEnemies(Enemy *Enemies[]);
void InitEnemies(std::vector<Enemy> Enemies);
void InitHuman(Human human);

void DestroyLocations(Location *locations[], int length);
void DestroyChallenges(Challenge *challenge[], int length);
void DestroyFleeChallenges(Challenge *challenge[], int length);
void DestroyMentalChallenges(Challenge *challenge[], int length);
void DestroyPhysicalChallenges(Challenge *challenge[], int length);
void DestroyEnemies(Player *player[], int length);
