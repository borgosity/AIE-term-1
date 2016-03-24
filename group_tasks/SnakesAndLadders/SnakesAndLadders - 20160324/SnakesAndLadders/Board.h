#pragma once
#include "Square.h"

class Board
{
public:
	Board();
	Board(Square * gameBoard);
	~Board();
	Square GetGameBoard() const;
	void operator=(Square * gameBoard);
private:
	Square * m_GameBoard;

};

