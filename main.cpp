
#include <iostream>
#include <Windows.h>

#include "Function.h"
#include "Snake.h"

void Apple(COORD& c, char symb, COORD* snake);

using namespace std;

int main() {

    SetConsoleOption(); // Забороняю міняти розмір вікна консолі

    SetConsoleOutputCP(1251); // використання кирилиці
    SetConsoleCP(1251); // використання кирилиці

    srand(time(0)); // запускаємо рандомну генерацію відповідно до часу в даний момент


    system("mode con cols=80 lines=40"); // Встанлодюємо розміри вікна
    SetColor(0x00);
    system("cls");

    // Створюємо основні змінні програми

    const int width = 80, height = 40; // Розмір поля, ширина та висота
    int sleep_time = 75; // Частота кадрів
    char symb = ' ';
    bool flag = true, flagApple = false;
    int direct = 87;
    int length = 3;
    COORD c, cordApple{};


    // Малюємо рамку

    SetColor(0x44);

    for (int i = 0; i < width; i++) {

        c.Y = 0;
        c.X = i;
        SetCursor(c);
        putchar(symb);

        c.Y = height - 1;
        SetCursor(c);
        putchar(symb);
    }

    for (int i = 0; i < height; i++) {

        c.Y = i;
        c.X = 0;
        SetCursor(c);
        putchar(symb);
        putchar(symb);

        c.X = width - 2;
        SetCursor(c);
        putchar(symb);
        putchar(symb);
    }

    SetColor(0x00);

    //apple(c, symb);

    // Створюємо об'єкт класа snake
    Snake snake(length, symb);

    // Цикл програми

    while (flag) {

        snake.Move(direct);

        if (flagApple == false) {
            Apple(cordApple, symb, snake.GetSnake());
            flagApple = true;
        }

        if (snake.GetSnakeHead().X == cordApple.X && snake.GetSnakeHead().Y == cordApple.Y) {

            flagApple = false;
            length++;
            snake.SetLenght(length);

        }

        for (int i = 1; i < length; i++) {
            if (snake.GetSnakeHead().X == snake.GetSnake()[i].X &&
                snake.GetSnakeHead().Y == snake.GetSnake()[i].Y) {
                flag = false;
            }
        }

        // Перевіряємо чи нажаті клавіші WASD та міняємо напрям якщо так

        if (GetAsyncKeyState(65) && direct != 68) {
            direct = 65;
        } else if (GetAsyncKeyState(83) && direct != 87) {
            direct = 83;
        } else if (GetAsyncKeyState(68) && direct != 65) {
            direct = 68;
        } else if (GetAsyncKeyState(87) && direct != 83) {
            direct = 87;
        }

        // Перевіряємо чи змійка зіштовхнулась зі стінкою

        if (snake.GetSnakeHead().X < 4 && direct == 65) {
            flag = false;
        }
        if (snake.GetSnakeHead().X > 74 && direct == 68) {
            flag = false;
        }
        if (snake.GetSnakeHead().Y < 2 && direct == 87) {
            flag = false;
        }
        if (snake.GetSnakeHead().Y > 37 && direct == 83) {
            flag = false;
        }

        Sleep(sleep_time);

    }

    SetColor(0x0F);
    SetCursor({ 2, 1 });
    system("pause");

    return 0;
}

void Apple(COORD& c, char symb, COORD* snake) {

    bool flag = true;

    do {
        c.X = 2 * randint(1, 38);
        c.Y = randint(1, 38);

        // _msize(snake)/sizeof(snake) - довжина змійки length (я б міг її просто передати, хз як краще)

        for (int i = 0; i < _msize(snake) / sizeof(snake); i++) {
            if (c.X != snake[i].X && c.Y != snake[i].Y) {
                flag = false;
            }
        }

    } while (flag);


    SetCursor(c);
    SetColor(0x22);

    putchar(symb);
    putchar(symb);

}
