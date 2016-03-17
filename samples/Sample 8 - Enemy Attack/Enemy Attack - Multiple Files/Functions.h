#pragma once

#include "Types.h"



/******************************************************************************
Computes the distance to a specified Position in the world. This assumes that
the distance is to be measured from the origin, which is where the player is
located (the player can't move in this very simple game).
*******************************************************************************/
float distanceToPlayer(const Position & position);

/******************************************************************************
Returns a random float that lies in the range 0 to upperLimit
*******************************************************************************/
float randomFloat(float upperLimit);
