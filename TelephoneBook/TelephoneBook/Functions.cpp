#include <iostream>
#include <Windows.h>
#include <conio.h>
//#include <string.h>
//#include <stdlib.h>

#include "Functions.h"

using namespace std;

//-----------------------------------------------------------------------------
#define defaultColor 7
#define menuColor 11
#define nameLength 255
//-----------------------------------------------------------------------------
void AddPerson(PERSON * &pers, int &size);
void clearMenu();
void count(int size);
void cleanRedaktFrame();
//-----------------------------------------------------------------------------
void GotoXY(int c, int r)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cr = { c, r };
	SetConsoleCursorPosition(h, cr);
}
//-----------------------------------------------------------------------------
void SetColor(int color)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
}
//-----------------------------------------------------------------------------
void showmenu(int size, int sel)
{
	clearMenu();

	if (size == 0)
	{
		GotoXY(72, 2);
		SetColor(sel == 0 ? menuColor : defaultColor);
		cout << "Add person";

		GotoXY(75, 3);
		SetColor(sel == 1 ? menuColor : defaultColor);
		cout << "Exit";
	}
	else
	{
		GotoXY(72, 2);
		SetColor(sel == 0 ? menuColor : defaultColor);
		cout << "Add person";

		GotoXY(70, 3);
		SetColor(sel == 1 ? menuColor : defaultColor);
		cout << "Remove person";

		GotoXY(67, 4);
		SetColor(sel == 2 ? menuColor : defaultColor);
		cout << "Person modification";

		GotoXY(70, 5);
		SetColor(sel == 3 ? menuColor : defaultColor);
		cout << "Person search";

		GotoXY(75, 6);
		SetColor(sel == 4 ? menuColor : defaultColor);
		cout << "Show";

		GotoXY(75, 7);
		SetColor(sel == 5 ? menuColor : defaultColor);
		cout << "Exit";
	}

	SetColor(defaultColor);
}
//-----------------------------------------------------------------------------
void menu(PERSON *pers, int size)
{
	int sel = 0;

	while (true)
	{
		showmenu(size, sel);
		int cnt;
		if (size == 0)
			cnt = 2;
		else
			cnt = 6;

		int key = getch();
		if (key == 224)
			key = getch();

		if (key == 72 && 0 < sel) // Up
			sel--;
		else if (key == 80 && sel < cnt - 1) // Down
			sel++;
		else if (key == 13)
		{
			switch (sel)
			{
			case 0:
				AddPerson(pers, size);
				count(size);
				cleanRedaktFrame();
				//				Sort(person, size);
				break;
			case 1:
				if (size == 0)
					return;

				//	RemovePerson(arr, size);
				//	count(size);
				//	cleanRedaktPlace();
				//	Print(arr, size, 0);
				//	menu(size);
				//	break;
			case 2:
				//	EditPerson(arr, size);
				//	Print(arr, size, 0);
				//	menu(size);
				//	break;
			case 3:
				//	FindPerson(arr, size);
				//	cleanRedaktPlace();
				//	menu(size);
				//	break;
			case 4:
				//else if (key == 13 && sel == 4)
				//{
				//	ShowPerson(arr, size);
				//}
			case 5:
				return;
			}
		}
	}
}
//-----------------------------------------------------------------------------
void frame()
{
	int sLength = 0, fLength = 60, sWidth = 1, fWidth = 23;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			GotoXY(j, i);

			if (i == sWidth || i == fWidth - 1)
				cout << char(178);
			else if (j == sLength && sWidth < i && i < fWidth)
				cout << char(178);
			else if (j == fLength - 1 && sWidth < i && i < fWidth)
				cout << char(178);
		}
	}
}
//-----------------------------------------------------------------------------
void clearTable()
{
	int sLength = 1, fLength = 59, sWidth = 2, fWidth = 22;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			GotoXY(j, i);
			cout << " ";
		}
	}
}
//-----------------------------------------------------------------------------
void count(int size)
{
	GotoXY(35, 0);
	cout << "  ";
	GotoXY(35, 0);
	SetColor(10);
	cout << size;
	SetColor(7);
}
//-----------------------------------------------------------------------------
void clearMenu()
{
	int sLength = 62, fLength = 90, sWidth = 1, fWidth = 10;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			GotoXY(j, i);
			cout << " ";
		}
	}
}
//-----------------------------------------------------------------------------
void delimetr(short column, short row, int length, int color)
{
	GotoXY(column, row);
	SetColor(color);
	for (int i = 0; i < length; i++)
		cout << char(196);
	SetColor(7);
}
//-----------------------------------------------------------------------------
void redaktFrame()
{
	int sLength = 65, fLength = 110, sWidth = 14, fWidth = 25;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			GotoXY(j, i);

			if (i == sWidth || i == fWidth - 1)
				cout << char(178);
			else if (j == sLength && sWidth < i && i < fWidth)
				cout << char(178);
			else if (j == fLength - 1 && sWidth < i && i < fWidth)
				cout << char(178);
		}
	}
}
//-----------------------------------------------------------------------------
void cleanRedaktFrame()
{
	int sLength = 65, fLength = 115, sWidth = 14, fWidth = 25;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			GotoXY(j, i);

			cout << " ";
		}
	}
}
//-----------------------------------------------------------------------------
//int len(char **arr, int row)
//{
//	int length = 0;
//	while (arr[row][length] != '\0')
//		length++;
//	return length;
//}
//-----------------------------------------------------------------------------
void cleanRedaktPlace()
{
	for (short i = 24; i < 31; i++)
	{
		GotoXY(0, i);
		for (int k = 0; k < 60; k++)
			cout << " ";
	}
}
//-----------------------------------------------------------------------------
void fillRedaktPlace()
{
	short row = 15, column = 66;

	char names[5][10] = { "Name: ", "Surname: ", "Age: ", "Number: ", "Mail: " };

	for (int i = 0; i < 5; i++)
	{
		GotoXY(column, row++);
		cout << names[i];
		if (i != 4)
			delimetr(column, row++, 35, 14);
	}
}
//-----------------------------------------------------------------------------
void AddPerson(PERSON * &pers, int &size)
{
	redaktFrame();
	fillRedaktPlace();

	short row = 15, col = 75;

	PERSON temp;

	SetColor(10);

	GotoXY(col, row);
	//	fgets(temp.name, sizeof(temp.name)-1, stdin);
	cin.getline(temp.name, sizeof(temp.name) - 1);
	row += 2;

	GotoXY(col, row);
	cin.getline(temp.surname, sizeof(temp.surname) - 1);
	row += 2;

	GotoXY(col, row);
	char myage[10];
	cin.getline(myage, sizeof(myage) - 1);
	temp.age = atoi(myage);
	row += 2;

	GotoXY(col, row);
	cin.getline(temp.number, sizeof(temp.number) - 1);
	row += 2;

	GotoXY(col, row);
	cin.getline(temp.email, sizeof(temp.email) - 1);

	SetColor(7);

	PERSON *newpers = (PERSON*)calloc(size + 1, sizeof(PERSON));
	if (pers) // size > 0
	{
		memcpy(newpers, pers, size * sizeof(PERSON));
		free(pers);
	}

	pers = newpers;
	memcpy(&pers[size], &temp, sizeof(PERSON));
	size++;

	//	temp = (PERSON*)calloc(size, sizeof(temp));
	//	pers = (PERSON*)realloc(pers, (++size) * sizeof(PERSON));

}
//-----------------------------------------------------------------------------
//void printSurnameName(PERSON *arr, int index)
//{
//	cout << arr[index].surname << " " << arr[index].name;
//}
////-----------------------------------------------------------------------------
//void Print(PERSON *arr, int size, int index)
//{
//	short temp = 1, color;
//	clearTable();
//
//	if (index == 0)
//		color = 7;
//	else
//		color = 10;
//
//	for (short i = 0; i < size; i++)
//	{
//		SetConsoleCursorPosition(h, { 1, temp * 2 });
//		cout << "\t\t\t\t\t\t";
//		SetConsoleCursorPosition(h, { 1, temp * 2 });
//		cout << i + 1 << ". ";
//		SetColor(h, color);
//		printSurnameName(arr, i);
//		delimetr(1, temp * 2 + 1, 40, menuColor);
//		temp++;
//	}
//}
////-----------------------------------------------------------------------------
int fcmp(const void *A, const void *B)
{
	PERSON *a = (PERSON *)A;
	PERSON *b = (PERSON *)B;

	int r = strcmp(a->surname, b->surname);
	if (r == 0)
		r = strcmp(a->name, b->name);

	return r;
}

void Sort(PERSON *arr, int size)
{
	qsort(arr, size, sizeof(PERSON), fcmp);
}


//void Sort(PERSON *arr, int size)
//{
//	if (size == 1)
//		Print(arr, size, 0);
//	else
//	{
//		PERSON temp;
//		bool check = true;
//
//		for (int i = size - 1; i > 0; i--)
//		{
//			for (int j = 0; arr[i].surname[j] != '\0'; j++)
//			{
//				if (arr[i].surname[j] < arr[i - 1].surname[j])
//				{
//					temp = arr[i - 1];
//					arr[i - 1] = arr[i];
//					arr[i] = temp;
//					check = false;
//					break;
//				}
//				else if (arr[i].surname[j] > arr[i - 1].surname[j])
//				{
//					check = false;
//					break;
//				}
//			}
//
//			if (check)
//				for (int j = 0; arr[i].name[j] != '\0'; j++)
//				{
//					if (arr[i].name[j] < arr[i - 1].name[j])
//					{
//						temp = arr[i - 1];
//						arr[i - 1] = arr[i];
//						arr[i] = temp;
//						break;
//					}
//					else if (arr[i].name[j] > arr[i - 1].name[j])
//						break;
//				}
//		}
//
//		Print(arr, size, 0);
//	}
//}
////-----------------------------------------------------------------------------
//void RemovePerson(PERSON *p, int &size)
//{
//	int num = 0;
//	char *arrTemp = new char[1];
//	PERSON temp;
//	SetConsoleCursorPosition(h, { 0, 24 });
//	cout << "Enter the order number of student for remove: ";
//	SetColor(h, 10);
//	cin >> num;
//	SetColor(h, 7);
//	num--;
//
//	while (true)
//	{
//		if (num == size - 1 || size == 1)
//			break;
//
//		temp = p[num];
//		p[num] = p[num + 1];
//		p[num + 1] = temp;
//		num++;
//	}
//
//	delete[] p[size - 1];
//	size--;
//}
////-----------------------------------------------------------------------------
//void fillPersonData(PERSON *p, int index)
//{
//	short row = 15, col = 75;
//
//	SetColor(h, 10);
//	SetConsoleCursorPosition(h, { col, row });
//	cout << p[index].name;
//	row += 2;
//
//	SetConsoleCursorPosition(h, { col, row });
//	cout << p[index].surname;
//	row += 2;
//
//	SetConsoleCursorPosition(h, { col, row });
//	cout << p[index].age;
//	row += 2;
//
//	SetConsoleCursorPosition(h, { col, row });
//	cout << p[index].number;
//	row += 2;
//
//	SetConsoleCursorPosition(h, { col, row });
//	cout << p[index].email;
//
//	SetColor(h, 7);
//}
////-----------------------------------------------------------------------------
//void EditPerson(PERSON *arr, int size)
//{
//	cleanRedaktFrame();
//	int num = 0, age = 0;
//	SetConsoleCursorPosition(h, { 0, 24 });
//	cout << "Enter the order number of student for editing: ";
//	SetColor(h, 10);
//	cin >> num;
//	num--;
//	int index = num;
//	SetColor(h, 7);
//	cleanRedaktPlace();
//	redaktFrame();
//	fillRedaktPlace();
//	fillPersonData(arr, index);
//	SetConsoleCursorPosition(h, { 0, 24 });
//	cout << "Choice number of order for editing";
//	cout << "\n1. Name";
//	cout << "\n2. Surname";
//	cout << "\n3. Age";
//	cout << "\n4. Number";
//	cout << "\n5. Email";
//	cout << "\nChoice: ";
//	int choice;
//	SetColor(h, 10);
//	cin >> choice;
//	SetColor(h, 7);
//	cleanRedaktPlace();
//	cin.ignore();
//	SetConsoleCursorPosition(h, { 0, 24 });
//	
//	switch (choice)
//	{
//	case 1:
//		cout << "Input new name : ";
//		SetColor(h, 10);
//		cin.getline(arr[num].name, nameSurname);
//		SetColor(h, 7);
//	break;
//
//	case 2:
//		cout << "Input new surname : ";
//		SetColor(h, 10);
//		cin.getline(arr[num].surname, nameSurname);
//		SetColor(h, 7);
//	break;
//
//	case 3:
//		cout << "Input new age : ";
//		SetColor(h, 10);
//		cin >> age;
//		arr[num].age = age;
//		SetColor(h, 7);
//	break;
//
//	case 4:
//		cout << "Input new number : ";
//		SetColor(h, 10);
//		cin.getline(arr[num].number, phoneNumber);
//		SetColor(h, 7);
//	break;
//
//	case 5:
//		cout << "Input new email : ";
//		SetColor(h, 10);
//		cin.getline(arr[num].email, mail);
//		SetColor(h, 7);
//	}
//	cleanRedaktPlace();
//	redaktFrame();
//	fillRedaktPlace();
//	fillPersonData(arr, index);
//	SetConsoleCursorPosition(h, { 0, 24 });
//	cout << "Redact again?(y/n): ";
//	char sym;
//	cin >> sym;
//	if (sym == 'y')
//		EditPerson(arr, size);
//	else
//	{
//		cleanRedaktFrame();
//		cleanRedaktPlace();
//	}
//}
////-----------------------------------------------------------------------------
//int starChecker(char *arr)
//{
//	int index = 0, count = 0;
//	if (arr[index] != '*')
//		return 1;
//	while (arr[index] != '\0')
//	{
//		if (arr[index] == '*')
//			count++;
//		index++;
//	}
//
//	if (count == 1)
//		return 2;
//	else if (count == 2)
//		return 3;
//	else
//		return 4;
//}
////-----------------------------------------------------------------------------
//void Data(PERSON *arr, int choice, int num, int size)
//{
//	int index = 0, ageTemp = 0, count = 0;
//	bool check = true;
//	char temp[20] = {};
//	char *personTemp = new char[70];
//	short row = 25;
//
//	for (int i = 0; i < size; i++)
//	{
//		switch (choice)
//		{
//			case 1:
//				personTemp = arr[i].name;
//			break;
//
//			case 2:
//				personTemp = arr[i].surname;
//			break;
//
//			case 3:
//			{
//				ageTemp = arr[i].age;
//
//				if (num == 1)
//				{
//					if (int(ageTemp / 10) != temp[0])
//						check = false;
//
//					if (check)
//					{
//						SetConsoleCursorPosition(h, { 0, row });
//						printSurnameName(arr, i);
//						row++; count++;
//					}
//				}
//				else if (num == 2)
//				{
//					if (ageTemp % 10 != temp[1])
//						check = false;
//
//					if (check)
//					{
//						SetConsoleCursorPosition(h, { 0, row });
//						printSurnameName(arr, i);
//						row++; count++;
//					}
//				}
//				else
//				{
//					for (size_t i = 0; i < 2; i++)
//					{
//						if (int(ageTemp / 10) != temp[i] && i == 0 || ageTemp % 10 != temp[i] && i == 1)
//							check = false;
//						//else if (ageTemp % 10 != temp[i] && i == 1)
//						//	check = false;
//					}
//
//					if (check)
//					{
//						SetConsoleCursorPosition(h, { 0, row });
//						printSurnameName(arr, i);
//						row++; count++;
//					}
//				}
//			}
//			break;
//
//			case 4:
//				personTemp = arr[i].number;
//			break;
//
//			case 5:
//				personTemp = arr[i].email;
//		}
//
//		if (num == 1)
//		{
//			while (temp[index] != '*')
//			{
//				for (int j = 0; personTemp[j] != '\0'; j++)
//				{
//					if (personTemp[j] == temp[index])
//					{
//						for (int index = 0; temp[index] != '*'; index++, j++)
//						{
//							if (personTemp[j] != temp[index])
//								check = false;
//						}
//
//						if (check)
//						{
//							SetConsoleCursorPosition(h, { 0, row });
//							printSurnameName(arr, i);
//							row++; count++;
//						}
//					}
//				}
//			}
//		}
//		else if (num == 2)
//		{
//			while (temp[index] != '\0')
//			{
//				for (int j = 0; personTemp[j] != '\0'; j++)
//				{
//					if (personTemp[j] == temp[index])
//					{
//						for (int index = 1; temp[index] != '\0'; index++, j++)
//						{
//							if (personTemp[j] != temp[index])
//								check = false;
//						}
//
//						if (check)
//						{
//							SetConsoleCursorPosition(h, { 0, row });
//							printSurnameName(arr, i);
//							row++; count++;
//						}
//					}
//				}
//			}
//		}
//		else if (num == 3)
//		{
//			while (temp[++index] != '*' && temp[index] != '\0')
//			{
//				for (int j = 0; personTemp[j] != '\0'; j++)
//				{
//					if (personTemp[j] == temp[index])
//					{
//						for (int index = 1; temp[index] != '\0' && temp[index] != '*'; index++, j++)
//						{
//							if (personTemp[j] != temp[index])
//								check = false;
//						}
//
//						if (check)
//						{
//							SetConsoleCursorPosition(h, { 0, row });
//							printSurnameName(arr, i);
//							row++; count++;
//						}
//					}
//				}
//			}
//		}
//		else
//			while (temp[index] != '\0')
//			{
//				for (int j = 0; personTemp[j] != '\0'; j++)
//				{
//					if (personTemp[j] == temp[index])
//					{
//						for (int index = 0; temp[index] != '\0'; index++, j++)
//						{
//							if (personTemp[j] != temp[index])
//								check = false;
//						}
//
//						if (check)
//						{
//							SetConsoleCursorPosition(h, { 0, row });
//							printSurnameName(arr, i);
//							row++; count++;
//						}
//					}
//				}
//			}
//	}
//}
////-----------------------------------------------------------------------------
//void FindPerson(PERSON *arr, int size)
//{
//	char temp[20] = {};
//	int index = 0, checkNum = 0;
//	SetConsoleCursorPosition(h, { 0, 24 });
//	cout << "Choice number of order for search";
//	cout << "\n1. Name";
//	cout << "\n2. Surname";
//	cout << "\n3. Age";
//	cout << "\n4. Number";
//	cout << "\n5. Email";
//	cout << "\nChoice: ";
//	int choice = 0;
//	SetColor(h, 10);
//	cin >> choice;
//	SetColor(h, 7);
//	cin.ignore();
//	cleanRedaktPlace();
//	SetConsoleCursorPosition(h, { 0, 24 });
//
//	switch (choice)
//	{
//	case 1:
//		cout << "Input name or part of name(use \'*\' for redakt search): ";
//		SetColor(h, 10);
//		cin >> temp;
//		SetColor(h, 7);
//		checkNum = starChecker(temp);
//		Data(arr, choice, checkNum, size);
//
//
//	break;
//
//	//case 2:
//	//	cout << "Input new surname : ";
//	//	SetColor(h, 10);
//	//	cin.getline(arr[num].surname, nameSurname);
//	//	SetColor(h, 7);
//	//break;
//
//	//case 3:
//	//	cout << "Input new age : ";
//	//	SetColor(h, 10);
//	//	cin >> age;
//	//	arr[num].age = age;
//	//	SetColor(h, 7);
//	//break;
//
//	//case 4:
//	//	cout << "Input new number : ";
//	//	SetColor(h, 10);
//	//	cin.getline(arr[num].number, phoneNumber);
//	//	SetColor(h, 7);
//	//break;
//
//	//case 5:
//	//	cout << "Input new email : ";
//	//	SetColor(h, 10);
//	//	cin.getline(arr[num].email, mail);
//	//	SetColor(h, 7);
//	}
////	cleanRedaktPlace();
//	system("pause");
//}
////-----------------------------------------------------------------------------
//void ShowPerson(PERSON *arr, int size)
//{
//	clearMenu();
//	cleanRedaktFrame();
//	clearTable();
//
//	int index = 1, key = 0;
//
//	SetConsoleCursorPosition(h, { 0, 24 });
//	cout << "Enter \'e\' for edit person or \'esc\' to return to the menu";
//
//	while (true)
//	{
//		clearTable();
//		Print(arr, size, index);
//
//		key = getch();
//		if (key == 224)
//			key = getch();
//
//		if (key == 72 && index <= size) // Up
//			index--;
//		else if (key == 80 && index >= size) // Down
//			index++;
//		else if (key == 27) // esc
//			break;
//		else if (key == int('e'))
//			EditPerson(arr, size);
//
//		cleanRedaktFrame();
//		redaktFrame();
//		fillRedaktPlace();
//		fillPersonData(arr, --index);
//	}
//}
