#include <iostream>
#include "GameBoard.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Player playerOne;
	//Player playerTwo;

	//cout << "Please enter player one's name:" << endl;
	//cin >> playerOne.name;
	//cout << "Welcome " << playerOne.name << "!\n" << endl;
	//cout << "Please enter player two's name:" << endl;
	//cin >> playerTwo.name;
	//cout << "Welcome " << playerTwo.name << "!\n" << endl;
	//cout << "Let the game begin" << endl;

	//system("pause");
	//system("CLS");

	//GameBoard();

	GameBoard gameTest;
	gameTest.createBoardArr(gameTest, 4);
	gameTest.printBoardArr(gameTest, 4);

	while(true){}

	return 0;
}