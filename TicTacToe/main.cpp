#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

void invalidInput(int& num)
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Invalid input, please try again." << endl;
	cin >> num;
}

int main()
{
	bool playAgain = true;

	while (playAgain) //Play again loop
	{
		Player playerOne;
		Player playerTwo;

		int gameSize = 0; // game board size

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
		cin >> gameSize;

		//Invalid input catch
		while (gameSize < 3 || gameSize > 10 || !cin)
		{
			invalidInput(gameSize);
		}

		cout << "\nLet the game begin!" << endl;
		system("pause");

		bool winCondition = false; //Game loop condition
		int playAgainNum = 0;

		GameBoard gameTest; //Initialize game board

		system("CLS");
		gameTest.createBoardArr(gameTest, gameSize); //Populate game board based on size

		//Game loop
		while(!winCondition)
		{
			gameTest.printBoardArr(gameTest, gameSize); //Print board to console

			//Player one's turn
			cout << playerOne.name << "'s turn.\nEnter cell number to replace with 'X'" << endl;
			cin >> playerOne.cellChoice;

			//Invalid input catch
			while (playerOne.cellChoice > (gameSize * gameSize) || !cin || gameTest.board[(playerOne.cellChoice - 1) / gameSize][(playerOne.cellChoice - 1) % gameSize] < 0)
			{
				invalidInput(playerOne.cellChoice);
			}

			playerOne.cellChoice -= 1;
			gameTest.board[playerOne.cellChoice / gameSize][playerOne.cellChoice % gameSize] = -1; //Sets array coordinate respective to cell choice

			system("CLS");
			gameTest.printBoardArr(gameTest, gameSize); //Update board

			//Win check
			if (gameTest.winCheck(gameTest, gameSize, -1))
			{
				cout << playerOne.name << " wins!" << endl;
				system("pause");
				winCondition = true;
			}

			if (!winCondition)
			{
				//Tie check
				if (gameTest.tieCheck(gameTest, gameSize))
				{
					cout << "The game is a tie." << endl;
					system("pause");
					winCondition = true;
				}

				system("CLS");
				gameTest.printBoardArr(gameTest, gameSize);

				//Player two's turn
				cout << playerTwo.name << "'s turn.\nEnter cell number to replace with 'O'" << endl;
				cin >> playerTwo.cellChoice;

				//Invalid input check
				while (playerTwo.cellChoice > (gameSize * gameSize) || !cin || gameTest.board[(playerTwo.cellChoice - 1) / gameSize][(playerTwo.cellChoice - 1) % gameSize] < 0)
				{
					invalidInput(playerTwo.cellChoice);
				}

				playerTwo.cellChoice -= 1;
				gameTest.board[playerTwo.cellChoice / gameSize][playerTwo.cellChoice % gameSize] = -2; //Sets array coordinate respective to cell choice

				system("CLS");
				//Update board
				gameTest.printBoardArr(gameTest, gameSize);

				if (gameTest.winCheck(gameTest, gameSize, -2))
				{
					cout << playerTwo.name << " wins!" << endl;
					system("pause");
					winCondition = true;
				}

				if (!winCondition)
				{
					if (gameTest.tieCheck(gameTest, gameSize))
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