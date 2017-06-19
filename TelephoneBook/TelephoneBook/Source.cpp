#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	int size = 0;

	SetConsoleCursorPosition(w, { 15, 0 });
	cout << "STUDENT LIST | COUNT: ";
	SetConsoleTextAttribute(w, 10);
	cout << size;
	SetConsoleTextAttribute(w, 7);
	frame();

	SetConsoleCursorPosition(w, { 75, 0 });
	SetConsoleTextAttribute(w, 10);
	cout << "MENU";
	SetConsoleTextAttribute(w, 7);
	menu(size);

	SetConsoleCursorPosition(w, { 0, 23 });
	cout << endl;
}
