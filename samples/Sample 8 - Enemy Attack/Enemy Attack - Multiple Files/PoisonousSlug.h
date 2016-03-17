#pragma once

#include "Enemy.h"



// 'PoisonousSlug' is a specialisation of base-class 'Enemy' 
class PoisonousSlug : public Enemy
{
public:
    PoisonousSlug(const Position & position);
    virtual ~PoisonousSlug();

private:

    // Overrides from class Enemy
    virtual void onMove();
    virtual bool onAttack(std::string & killReason);
};


