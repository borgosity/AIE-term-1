#include <Math.h>
#include <stdlib.h>
#include "Functions.h"


float distanceToPlayer(const Position & position)
{
    return (float)sqrt(position.x * position.x + position.y * position.y + position.z * position.z);
}

float randomFloat(float upperLimit)
{
    return (float)rand() / (float)RAND_MAX * upperLimit;
}

