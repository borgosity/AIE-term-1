#include "FreddyKrueger.h"



/******************************************************************************
*******************************************************************************/
FreddyKrueger::FreddyKrueger()
{
}

/******************************************************************************
*******************************************************************************/
FreddyKrueger::~FreddyKrueger()
{
}

/******************************************************************************
*******************************************************************************/
bool FreddyKrueger::isAlive() const
{
	return m_health > 20.0f;
}

/******************************************************************************
*******************************************************************************/
void FreddyKrueger::takeHitFrom(const Weapon *weapon)
{
	if (weapon != 0)
	{
		m_health -= weapon->getDamage();
		if (m_health < 0)
		{
			m_health = 0;
		}
	}
}
