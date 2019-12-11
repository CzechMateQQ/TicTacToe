#include "GameBoard.h"
#include <iostream>
#include <stdio.h>
#include <string>

GameBoard::GameBoard()
{     
}

GameBoard::~GameBoard()
{
}

//Define board cell numbers
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

//Print numbers in respective cells for user readability and interaction
void GameBoard::printBoardArr(GameBoard& game, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
			for (int j = 0; j < _size; ++j)
			{
				//Multi digit cell numbers require less spacing
				if (game.board[i][j] < 10)
				{
					//If cell number is greater than 0 (unselected), convert to string
					//Else print 'X' or 'O' based on playerOne = -1 and playerTwo = -2
					std::string tmp = game.board[i][j] > 0 ? 
						std::to_string(game.board[i][j]) : game.board[i][j] == -1 ?  "X":"O";
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
			//Check rows
			if (game.board[i][j] == player)
			{
				horiz++;
			}
			//Check columns
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
			//i value is equal to j value for entire diagonal
			if (i == j && game.board[i][j] == player)
			{
				diagOne++;
			}
			//i + j is equal to one less than the board size for entire diagonal
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
	//Tie occurs when all spaces are filled and no winner
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
