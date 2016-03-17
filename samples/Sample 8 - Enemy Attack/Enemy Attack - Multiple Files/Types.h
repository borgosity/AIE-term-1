#pragma once


static const int NUM_ENEMIES = 5;
static const float WORLD_SIZE = 1000.0f;

// A single position in the world. Note that a Position will automatically
// initialize to (0,0,0)
struct Position
{
    float x;
    float y;
    float z;

    Position()
    {
        x = y = z = 0;
    }

    Position(float x_, float y_, float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
};

