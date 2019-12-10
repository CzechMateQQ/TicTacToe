#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool playAgain = true;
	//Play again loop
	while (playAgain)
	{
		Player playerOne;
		Player playerTwo;

		int size = 0;

		//Obtain player data and game board data
		cout << "Please enter player one's name:" << endl;
		cin >> playerOne.name;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Welcome " << playerOne.name << "!\n" << endl;

		cout << "\nPlease enter player two's name:" << endl;
		cin >> playerTwo.name;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Welcome " << playerTwo.name << "!\n" << endl;

		cout << "Please select game board size from 3 to 10" << endl;
		cin >> size;

		while (size < 3 || size > 10 || !cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input, please try again." << endl;
			cin >> size;
		}

		cout << "\nLet the game begin!" << endl;
		system("pause");

		bool winCondition = false;
		int playAgainNum = 0;

		GameBoard gameTest;

		system("CLS");
		gameTest.createBoardArr(gameTest, size);

		//Game loop
		while(!winCondition)
		{
			gameTest.printBoardArr(gameTest, size);

			cout << playerOne.name << "'s turn.\nEnter cell symbol to replace with 'X'" << endl;
			cin >> playerOne.cellChoice;

			while (playerOne.cellChoice > (size * size) || !cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input, try again:" << endl;
				cin >> playerOne.cellChoice;
			}

			playerOne.cellChoice -= 1;
			gameTest.board[playerOne.cellChoice / size][playerOne.cellChoice % size] = -1;

			system("CLS");
			gameTest.printBoardArr(gameTest, size);

			if (gameTest.winCheck(gameTest, size, -1))
			{
				cout << playerOne.name << " wins!" << endl;
				system("pause");
				winCondition = true;
			}

			if (!winCondition)
			{
				if (gameTest.tieCheck(gameTest, size))
				{
					cout << "The game is a tie." << endl;
					system("pause");
					winCondition = true;
				}

				system("CLS");
				gameTest.printBoardArr(gameTest, size);

				cout << playerTwo.name << "'s turn.\nEnter cell symbol to replace with 'O'" << endl;
				cin >> playerTwo.cellChoice;

				while (playerTwo.cellChoice > (size * size) || !cin)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid input, try again:" << endl;
					cin >> playerTwo.cellChoice;
				}

				playerTwo.cellChoice -= 1;
				gameTest.board[playerTwo.cellChoice / size][playerTwo.cellChoice % size] = -2;

				system("CLS");
				gameTest.printBoardArr(gameTest, size);

				if (gameTest.winCheck(gameTest, size, -2))
				{
					cout << playerTwo.name << " wins!" << endl;
					system("pause");
					winCondition = true;
				}

				if (!winCondition)
				{
					if (gameTest.tieCheck(gameTest, size))
					{
						cout << "The game is a tie." << endl;
						system("pause");
						winCondition = true;
					}
				}
			}
			system("CLS");
		}
		cout << "Would you like to play again?\nPress '1' for yes\nPress '2' for no" << endl;
		cin >> playAgainNum;

		if (playAgainNum == 1)
		{
			playAgain = true;
			winCondition = false;
			system("CLS");
		}
		else
		{
			playAgain = false;
		}
	}

	return 0;
}