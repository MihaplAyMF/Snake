#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

class Snake {

	int length{};
	char symb;
	COORD* snakeCord = new COORD[length];

public:

	Snake(int lenght, char symb);
	~Snake();
	void Draw();
	void Move(int direct);
	COORD GetSnakeHead();
	COORD* GetSnake();
	void SetLenght(int length);
};

