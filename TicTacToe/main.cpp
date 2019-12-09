#include <iostream>
#include "GameBoard.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Player playerOne;
	Player playerTwo;

	int size = 0;

	//Obtain player and game board data
	cout << "Please enter player one's name:" << endl;
	cin >> playerOne.name;
	cout << "Welcome " << playerOne.name << "!\n" << endl;
	cout << "Please enter player two's name:" << endl;
	cin >> playerTwo.name;
	cout << "Welcome " << playerTwo.name << "!\n" << endl;
	cout << "Please select game board size from 3 to 9" << endl;
	cin >> size;

	while (size < 3 || size > 9 || !cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input, please try again." << endl;
		cin >> size;
	}

	cout << "Let the game begin!" << endl;
	system("pause");
	system("CLS");

	//GameBoard();

	bool winCondition = false;

	GameBoard gameTest;

	gameTest.createBoardArr(gameTest, size);
	gameTest.printBoardArr(gameTest, size);

	//Game loop
	while(!winCondition)
	{
		cout << playerOne.name << "'s turn.\nEnter cell symbol to replace with 'X'" << endl;
		cin >> playerOne.cellChoice;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (playerOne.cellChoice == gameTest.board[i][j])
				{
					gameTest.board[i][j] == 'X';
				}
			}
		}

		system("CLS");
		gameTest.printBoardArr(gameTest, size);

		cout << playerTwo.name << "'s turn.\nEnter cell symbol to replace with 'O'" << endl;
		cin >> playerTwo.cellChoice;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (playerTwo.cellChoice == gameTest.board[i][j])
				{
					gameTest.board[i][j] == 'O';
				}
			}
		}

		system("CLS");
		gameTest.printBoardArr(gameTest, size);
	}

	return 0;
}