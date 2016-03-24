#include "Square.h"

Square::Square()
{
}

Square::Square(int squareType, int boardPos, int moveNum)
{
	m_squareType = squareType;
	m_boardPos = boardPos;
	m_moveNum = moveNum;
}

Square::~Square()
{
}

Square Square::GetSquare() const
{
	return *this;
}

int Square::BoardPos()
{
	return m_boardPos;
}

int Square::Move() const
{
	return m_moveNum;
}


