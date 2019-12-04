#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	GameBoard(size_t size);

	int board[3][3];
	void createBoardArr(GameBoard& game, size_t size);
	void printBoardArr(GameBoard& game, size_t size);
};

