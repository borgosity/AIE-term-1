#pragma once
#include <vector>

//location includes
#include "StartLocation.h"
#include "GeneralLocation.h"
#include "FinishLocation.h"

//player includes
#include "Human.h"
#include "Enemy.h"

// challenge includes
#include "FleeChallenge.h"
#include "MentalChallenge.h"
#include "PhysicalChallenge.h"

void InitLocations(Location *locations[]);
void InitFleeChallenges(Challenge *challenge[]);
void InitMentalChallenges(Challenge *challenge[]);
void InitPhysicalChallenges(Challenge *challenge[]);
void InitEnemies(Player *player[]);
void InitHuman(Human human);