#include "Tiger.h"
#include "Functions.h"



/******************************************************************************
*******************************************************************************/
Tiger::Tiger(const Position & position)
    : Enemy(position)
{

}

/******************************************************************************
*******************************************************************************/
Tiger::~Tiger()
{

}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
void Tiger::onMove()
{
    // Archer-specific code goes here
    // ...
}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
bool Tiger::onAttack(std::string & killReason)
{
    Enemy::onAttack(killReason);

    // Archer-specific code goes here
    // ...
    if (randomFloat(100) < 10.0f)
    {
        killReason = "Eaten by a stripey cat.";
        return false;
    }

    return true;
}
