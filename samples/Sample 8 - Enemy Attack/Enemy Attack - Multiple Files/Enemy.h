#pragma once

#include <string>
#include "Types.h"



// 'Enemy' is the base class for all enemies in the game.
// It is an abstract base class (i.e. pure virtual) that cannot
// be instantiated by itself.
class Enemy
{
public:
    Enemy();
    Enemy(const Position & position);

    virtual ~Enemy();

    virtual void onMove() = 0;

    virtual bool onAttack(std::string & killReason);

private:
    Position m_position;
    float m_health;
    float m_speed;
    float m_distanceToPlayer;

    void init();
};

