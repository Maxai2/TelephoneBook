#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	int size = 10;

	Person *pers;
	pers = (Person*)calloc(size, sizeof(Person));

	SetConsoleCursorPosition(w, { 15, 0 });
	cout << "PHONE BOOK | COUNT: ";
	SetConsoleTextAttribute(w, 10);
	cout << size;
	SetConsoleTextAttribute(w, 7);
	frame();

	SetConsoleCursorPosition(w, { 75, 0 });
	SetConsoleTextAttribute(w, 10);
	cout << "MENU";
	SetConsoleTextAttribute(w, 7);
	menu(pers, size);

	SetConsoleCursorPosition(w, { 0, 23 });
	cout << endl;
}
