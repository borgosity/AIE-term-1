#pragma once

#include "Enemy.h"



// 'EnemyArcher' is a specialisation of base-class 'Enemy' 
class EnemyArcher : public Enemy
{
public:
    EnemyArcher(const Position & position);
    virtual ~EnemyArcher();

private:

    // Overrides from class Enemy
    virtual void onMove();
    virtual bool onAttack(std::string & killReason);
};

