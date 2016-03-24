#include "Board.h"



Board::Board()
{
}

Board::Board(Square * gameBoard)
{
	m_GameBoard = gameBoard;
}


Board::~Board()
{
}

Square Board::GetGameBoard() const
{
	return *m_GameBoard;
}

void Board::operator=(Square * gameBoard)
{
	m_GameBoard = gameBoard;
}
