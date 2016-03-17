#include "KillerBee.h"
#include "Functions.h"



/******************************************************************************
*******************************************************************************/
KillerBee::KillerBee(const Position & position)
    : Enemy(position)
{

}

/******************************************************************************
*******************************************************************************/
KillerBee::~KillerBee()
{

}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
void KillerBee::onMove()
{
    // Archer-specific code goes here
    // ...
}

/******************************************************************************
Overridden from Enemy
*******************************************************************************/
bool KillerBee::onAttack(std::string & killReason)
{
    Enemy::onAttack(killReason);

    // Archer-specific code goes here
    // ...
    if (randomFloat(100) < 10.0f)
    {
        killReason = "Stung on the lip, got a swollen mouth, couldn't eat, finally died of starvation";
        return false;
    }

    return true;
}
