#pragma once

class Square
{
public:
	Square();
	Square(int squareType, int boardPos, int moveNum);
	~Square();
	Square GetSquare() const;
	int BoardPos();
	int Move() const;
private:
	int m_squareType;
	int m_boardPos;
	int m_moveNum;
};

