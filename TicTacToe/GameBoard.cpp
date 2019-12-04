#include "GameBoard.h"



GameBoard::GameBoard()
{     
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "_______" << "|" << "_______" << "|" << "_______" << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "_______" << "|" << "_______" << "|" << "_______" << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
	cout << "       " << "|" << "       " << "|" << "       " << endl;
}

GameBoard::GameBoard(size_t size)
{
	//for (int x = 0; x < size; ++x)
	//{
	//	for (int y = 0; y < size; ++y)
	//	{

	//	}
	//}
}

void GameBoard::createBoardArr(GameBoard& game, size_t size)
{
	int val = 1;
	for (int x = 0; x < size; ++x)
	{
		for (int y = 0; y < size; ++y)
		{
			game.board[x][y] = val;
			val++;
		}
	}
}

void GameBoard::printBoardArr(GameBoard& game, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << game.board[i][j] << " ";
		}
		cout << endl;
	}
}

GameBoard::~GameBoard()
{
}
