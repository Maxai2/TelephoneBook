#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);

#define nameSurnmae 50
#define mail 60
#define phoneNumber 20
//--------------------------------------

struct Person
{
	char name[nameSurnmae];
	char surname[nameSurnmae];
	int age;
	char number[phoneNumber];
	char email[mail];
};

int main()
{
	int size = 0;
	struct Person arr[size] = {};

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
	menu(p, size);

	SetConsoleCursorPosition(w, { 0, 23 });
	cout << endl;
}