#include "Monster.h"



/******************************************************************************
*******************************************************************************/
Monster::Monster(const std::string & name)
{
    m_name = name;
	m_gun = new Gun;
}

/******************************************************************************
*******************************************************************************/
Monster::~Monster()
{
	if (m_gun)
	{
		delete m_gun;
		m_gun = 0;
	}
}

/******************************************************************************
This function should copy the 'internals' of 'other' (i.e. all its member 
variables) over to *this.
*******************************************************************************/
void Monster::copy(const Monster & other)
{
	m_name = other.m_name;
	*m_gun = *other.m_gun;
}

/******************************************************************************
*******************************************************************************/
Gun & Monster::gun() const
{
	return *m_gun;
}





///******************************************************************************
//Copy constructor - implements a deep copy of 'other' to *this
//*******************************************************************************/
//Monster::Monster(const Monster & other)
//{
//    m_gun = new Gun;
//    *m_gun = other.gun();
//}

/******************************************************************************
Assignment operator - implements a deep copy of 'other' to *this
*******************************************************************************/
//Monster & Monster::operator=(const Monster & other)
//{
//    if (&other != this) // Prevent self-assignment
//    {
//        *m_gun = other.gun();
//    }
//    return *this;
//}

