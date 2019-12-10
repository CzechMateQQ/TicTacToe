#include "GameBoard.h"
#include <iostream>
#include <stdio.h>
#include <string>

GameBoard::GameBoard()
{     
}

void GameBoard::createBoardArr(GameBoard& game, int _size)
{
	int val = 1;
	game.board= new int*[_size];
	//Set GameBoard values incrementing from 1
	for (int i = 0; i < _size; ++i)
	{
		game.board[i] = new int[_size];
		for (int j = 0; j < _size; ++j)
		{
			game.board[i][j] = val;
			val++;
		}
	}
}

void GameBoard::printBoardArr(GameBoard& game, int _size)
{
	//Print numbers 1 to "_size" in respective cells for
	//user readability and interaction
	for (int i = 0; i < _size; ++i)
	{
			for (int j = 0; j < _size; ++j)
			{
				if (game.board[i][j] < 10)
				{
					std::string tmp = game.board[i][j] > 0 ? std::to_string(game.board[i][j]) : game.board[i][j] == -1 ?  "X":"O";
					cout << "   " << tmp << "  " << "|";
				}
				else if(game.board[i][j] >= 10 && game.board[i][j] < 100)
				{
					cout << "  " << game.board[i][j] << "  " << "|";
				}
				else
				{
					cout << "  " << game.board[i][j] << " " << "|";
				}
			}
			cout << endl;

		int line = 0;
		while (line < _size)
		{
			cout << "______|";
			line ++;
		}
		cout << endl;
	}
}

bool GameBoard::winCheck(GameBoard& game, int _size, int player)
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

		if (horiz == _size || vert == _size)
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
			if ((i + j) == (_size - 1) && game.board[i][j] == player)
			{
				diagTwo++;
			}
		}

		if (diagOne == _size || diagTwo == _size)
		{
			return true;
		}
	}
	return false;
}

bool GameBoard::tieCheck(GameBoard& game, int _size)
{
	int counter = 0;
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < _size; ++j)
		{
			if (game.board[i][j] < 0)
			{
				counter++;
			}
		}
	}
	if (counter == _size * _size)
	{
		return true;
	}
	return false;
}

GameBoard::~GameBoard()
{
}
