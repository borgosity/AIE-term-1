#include "EnemyArcher.h"
#include "Functions.h"



/******************************************************************************
*******************************************************************************/
EnemyArcher::EnemyArcher(const Position & position)
    : Enemy(position)
{

}

/******************************************************************************
*******************************************************************************/
EnemyArcher::~EnemyArcher()
{

}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
void EnemyArcher::onMove()
{
    // Archer-specific code goes here
    // ...
}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
bool EnemyArcher::onAttack(std::string & killReason)
{
    Enemy::onAttack(killReason);

    // Archer-specific code goes here
    // ...
    if (randomFloat(100) < 8.0f)
    {
        killReason = "Hit between the eyes by an arrow.";
        return false;
    }

    return true;
}
