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

	void createBoardArr(GameBoard& game, int _size);
	void printBoardArr(GameBoard& game, int _size);
	bool winCheck(GameBoard& game, int _size, int player);
	bool tieCheck(GameBoard& game, int _size);

	int boardSize;
	int** board;
};

