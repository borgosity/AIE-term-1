#include "PoisonousSlug.h"
#include "Functions.h"



/******************************************************************************
*******************************************************************************/
PoisonousSlug::PoisonousSlug(const Position & position)
    : Enemy(position)
{

}

/******************************************************************************
*******************************************************************************/
PoisonousSlug::~PoisonousSlug()
{

}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
void PoisonousSlug::onMove()
{
    // Archer-specific code goes here
    // ...
}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
bool PoisonousSlug::onAttack(std::string & killReason)
{
    Enemy::onAttack(killReason);

    // Archer-specific code goes here
    // ...
    if (randomFloat(100) < 2.0f)
    {
        killReason = "Painfully poisoned.";
        return false;
    }

    return true;
}
