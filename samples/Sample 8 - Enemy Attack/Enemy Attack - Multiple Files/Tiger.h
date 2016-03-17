#pragma once

#include "Enemy.h"



// 'Tiger' is a specialisation of base-class 'Enemy' 
class Tiger : public Enemy
{
public:
    Tiger(const Position & position);
    virtual ~Tiger();

private:

    // Overrides from class Enemy
    virtual void onMove();
    virtual bool onAttack(std::string & killReason);
};

