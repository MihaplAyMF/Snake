
#include "Function.h"

HWND hWnd;
HMENU hm;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci = { sizeof(cci), false };


int randint(int start, int end) {
	return rand() % end + start;
}

void SetConsoleOption() {

	if ((hWnd = GetConsoleWindow()) == NULL) {
		printf("No console window!?\n");
	}

	hm = GetSystemMenu(hWnd, FALSE);
	RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hWnd);

	SetConsoleCursorInfo(h, &cci);
}

void SetCursor(COORD c) {
	SetConsoleCursorPosition(h, c);
}

void SetColor(int color) {
	SetConsoleTextAttribute(h, color);
}