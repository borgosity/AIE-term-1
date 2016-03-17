#pragma once

#include "Enemy.h"



// 'KillerBee' is a specialisation of base-class 'Enemy' 
class KillerBee : public Enemy
{
public:
    KillerBee(const Position & position);
    virtual ~KillerBee();

private:

    // Overrides from class Enemy
    virtual void onMove();
    virtual bool onAttack(std::string & killReason);
};

