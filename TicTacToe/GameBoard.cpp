#include "GameBoard.h"
#include <iostream>
#include <stdio.h>



GameBoard::GameBoard()
{     
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "_______" << "|" << "_______" << "|" << "_______" << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "_______" << "|" << "_______" << "|" << "_______" << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
	//cout << "       " << "|" << "       " << "|" << "       " << endl;
}

//void GameBoard::createBoardArr(GameBoard& game, int _size)
//{
//	int val = 1;
//	//Set GameBoard values incrementing from 1
//	for (int i = 0; i < _size; ++i)
//	{
//		for (int j = 0; j < _size; ++j)
//		{
//			game.board[i][j] = val;
//			val++;
//		}
//	}
//
//	//for (int i = 0; i < _size; ++i)
//	//{
//	//	for (int j = 0; j < _size; ++j)
//	//	{
//	//		*intToChar[i][j] = '0' + *game.board[i];
//	//	}
//	//}
//}

void GameBoard::createBoardArr(GameBoard& game, int _size)
{
	int val = 33;
	//Set GameBoard values incrementing from 1
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < _size; ++j)
		{
			game.board[i][j] = val;
			val++;
		}
	}
}

//void GameBoard::printBoardArr(GameBoard& game, int _size)
//{
//	//Print numbers 1 to "_size" in respective cells for
//	//user readability and interaction
//	for (int i = 0; i < _size; ++i)
//	{
//		if (*game.board[i] < 10)
//		{
//			for (int j = 0; j < _size; ++j)
//			{
//				cout << "   "  << *game.board[i] << "  " << "|";
//			}
//			cout << endl;
//		}
//		else
//		{
//			for (int j = 0; j < _size; ++j)
//			{
//				cout << "  " << *game.board[i] << "  " << "|";
//			}
//			cout << endl;
//		}
//		int line = 0;
//		while (line < _size * _size)
//		{
//			cout << "______|";
//			line += 6;
//		}
//		cout << endl;
//	}
//
//	//Convert to char array for 'X' and 'O' swaps
//	intToChar = (char*)game.board;
//}

void GameBoard::printBoardArr(GameBoard& game, int _size)
{
	//Print numbers 1 to "_size" in respective cells for
	//user readability and interaction
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < _size; ++j)
		{
			cout << "   " << game.board[i][j] << "  " << "|";
		}
		cout << endl;
		
		int line = 0;
		while (line < _size * _size)
		{
			cout << "______|";
			line += 6;
		}
		cout << endl;
	}
}

bool GameBoard::winCheck(GameBoard& game, int _size, char player)
{
	int horiz = 0;
	int vert = 0;
	int diagOne = 0;
	int diagTwo = 0;

	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < _size; ++j)
		{
			if (game.board[i][j] == player)
			{
				horiz++;
			}
			if (game.board[j][i] == player)
			{
				vert++;
			}
		}

		if (horiz == 3 || vert == 3)
		{
			return true;
		}
		horiz = 0;
		vert = 0;
	}

	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < _size; ++j)
		{
			if (i == j && game.board[i][j] == player)
			{
				diagOne++;
			}
			if (i + j == _size + 1 && game.board[i][j] == player)
			{
				diagTwo++;
			}
		}

		if (diagOne == _size || diagTwo == _size)
		{
			return true;
		}
	}
}

GameBoard::~GameBoard()
{
}
