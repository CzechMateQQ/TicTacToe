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
	void turn();
	char name[10];
	int cellChoice;
};