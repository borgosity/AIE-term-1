#include <iostream>
#include <vector>
#include <memory>

#include "Square.h"
#include "Board.h"
void init()
{
	const int boardSize = 64;
	const int moverNum = 12;

	const int emptyType = 0;
	const int snakeType = 1;
	const int ladderType = 2;
	std::vector<std::shared_ptr<Square>> BoardVector;
	std::vector<std::shared_ptr<Square>> Movers;

	for (int i = 0; i < boardSize; i++)
	{
		BoardVector.push_back(std::make_shared<Square>(emptyType, i, 0));
	}

	Movers.push_back(std::make_shared<Square>(snakeType, 60, 59)); //snake 1 square 60 - move back 59 squares
	Movers.push_back(std::make_shared<Square>(snakeType, 46, 44)); //snake 2 square 46 - move back 44 squares
	Movers.push_back(std::make_shared<Square>(snakeType, 52, 42)); //snake 3 square 52 - move back 42 squares
	Movers.push_back(std::make_shared<Square>(snakeType, 49, 46)); //snake 4 square 49 - move back 46 squares
	Movers.push_back(std::make_shared<Square>(snakeType, 34, 18)); //snake 5 square 34 - move back 18 squares
	Movers.push_back(std::make_shared<Square>(snakeType, 37, 32)); //snake 6 square 37 - move back 32 squares
	Movers.push_back(std::make_shared<Square>(ladderType, 6, 19)); //ladder 1 square 06 - move forward 19 squares
	Movers.push_back(std::make_shared<Square>(ladderType, 15, 32)); //ladder 2 square 15 - move forward 32 squares
	Movers.push_back(std::make_shared<Square>(ladderType, 8, 40)); //ladder 3 square 8 - move forward 40 squares
	Movers.push_back(std::make_shared<Square>(ladderType, 29, 15)); //ladder 4 square 29 - move forward 15 squares
	Movers.push_back(std::make_shared<Square>(ladderType, 4, 49)); //ladder 5 square 4 - move forward 49 squares
	Movers.push_back(std::make_shared<Square>(ladderType, 14, 47)); //ladder 6 square 14 - move forward 47 squares

	for (int i = 0; i < moverNum; i++)
	{
		BoardVector[Movers[i]->BoardPos()] = Movers[i];
	}

	for (int i = 0; i < boardSize; i++)
	{
		//std::cout << BoardSquares.GetGameBoard().BoardPos() << "\n";
	}
}
int main()
{
	init();
	
	//const int boardSize = 64;
	//const int moverNum = 12;

	//const int emptyType = 0;
	//const int snakeType = 1;
	//const int ladderType = 2; 
	//Square * GameBoard[boardSize];
	//Board BoardSquares(*GameBoard);
	////Board BoardSquares();
	//Square *Movers[moverNum];

	//for (int i = 0; i < boardSize; i++)
	//{
	//	GameBoard[i] = new Square(emptyType,i,0);
	//}
	//Square * Something = BoardSquares.GetGameBoard;

	//Movers[0]  = new Square(snakeType,60,59); //snake 1 square 60 - move back 59 squares
	//Movers[1]  = new Square(snakeType,46,44); //snake 2 square 46 - move back 44 squares
	//Movers[2]  = new Square(snakeType,52,42); //snake 3 square 52 - move back 42 squares
	//Movers[3]  = new Square(snakeType,49,46); //snake 4 square 49 - move back 46 squares
	//Movers[4]  = new Square(snakeType,34,18); //snake 5 square 34 - move back 18 squares
	//Movers[5]  = new Square(snakeType,37,32); //snake 6 square 37 - move back 32 squares
	//Movers[6]  = new Square(ladderType,6,19); //ladder 1 square 06 - move forward 19 squares
	//Movers[7]  = new Square(ladderType,15,32); //ladder 2 square 15 - move forward 32 squares
	//Movers[8]  = new Square(ladderType,8,40); //ladder 3 square 8 - move forward 40 squares
	//Movers[9]  = new Square(ladderType,29,15); //ladder 4 square 29 - move forward 15 squares
	//Movers[10] = new Square(ladderType,4,49); //ladder 5 square 4 - move forward 49 squares
	//Movers[11] = new Square(ladderType,14,47); //ladder 6 square 14 - move forward 47 squares

	//for (int i = 0; i < moverNum; i++)
	//{
	//	GameBoard[Movers[i]->BoardPos()] = Movers[i];
	//}

	//for (int i = 0; i < boardSize; i++)
	//{
	//	//std::cout << BoardSquares.GetGameBoard().BoardPos() << "\n";
	//}
	std::cout << "finished!!\n\n";
	return 0;
}