

#include "Snake.h"
#include "Function.h"

// Функція зсуву координат змійки 

void Landslide(COORD* (&snake), int length) {

	for (int i = length - 1; i > 0; i--) {
		snake[i] = snake[i - 1];
	}

}

void Copy(COORD* (&snake), COORD* (&copySnake), int n) {

	for (int i = 0; i < n; i++) {
		snake[i] = copySnake[i];
	}
}

// Реалізуємо методи класу snake

Snake::Snake(int length, char symb) {
	this->length = length;
	this->symb = symb;
	snakeCord = new COORD[length + 1]; // snakeCord - динамічний масив координат тіла змійки
	int x = 2 * randint(10, 20);
	int y = 10;
	COORD c; // c - cord (x, y)

	// Виводимо усю змійку

	SetColor(0x11);

	for (int i = 0; i < length; i++) {
		snakeCord[i].X = x;
		snakeCord[i].Y = y;
		y++;
		c = snakeCord[i];
		SetCursor(c);
		putchar(symb);
		putchar(symb);
	}
}

Snake::~Snake() {
	delete snakeCord;
}

void Snake::Move(int direct) {

	switch (direct) {
		case 87: // UP
			Landslide(snakeCord, length + 1);
			snakeCord[0].Y -= 1;
			break;
		case 68: // RIGHT
			Landslide(snakeCord, length + 1);
			snakeCord[0].X += 2;
			break;
		case 83: // DOWN
			Landslide(snakeCord, length + 1);
			snakeCord[0].Y += 1;
			break;
		case 65: // LEFT
			Landslide(snakeCord, length + 1);
			snakeCord[0].X -= 2;
			break;
	}

	Draw();
}

// Я не буду виводити усю змійку, а лише переміщеннвя голови та видалятиму останній блок 

void Snake::Draw() {

	COORD c = snakeCord[length];
	SetCursor(c);
	SetColor(0x00);

	putchar(symb);
	putchar(symb);

	c = snakeCord[0];
	SetCursor(c);
	SetColor(0x11);

	putchar(symb);
	putchar(symb);

}

COORD Snake::GetSnakeHead() {
	return snakeCord[0];
}

COORD* Snake::GetSnake() {
	return snakeCord;
}

void Snake::SetLenght(int length) {
	this->length = length;

	COORD* copyX = new COORD[length+1];
	Copy(copyX, snakeCord, length);
	snakeCord = new COORD[length+1];
	Copy(snakeCord, copyX, length);
	delete copyX;
}
