#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Player
{
public:
	Player();
	~Player();

	char name[10];
	int cellChoice;
};