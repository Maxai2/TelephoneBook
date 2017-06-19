#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

#define nameSurname 50
#define mail 60
#define phoneNumber 20
#define ageNumber 3
//--------------------------------------
#define defaultColor 7
#define menuColor 11
#define nameLength 255

struct Person
{
	char name[nameSurname];
	char surname[nameSurname];
	//char age[ageNumber];
	int age;
	char number[phoneNumber];
	char email[mail];
};

void frame()
{
	int sLength = 0, fLength = 60, sWidth = 1, fWidth = 23;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });

			if (i == sWidth || i == fWidth - 1)
				cout << char(178);
			else if (j == sLength && sWidth < i && i < fWidth)
				cout << char(178);
			else if (j == fLength - 1 && sWidth < i && i < fWidth)
				cout << char(178);
		}
	}
}

void clearTable()
{
	int sLength = 1, fLength = 59, sWidth = 2, fWidth = 22;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });
			cout << " ";
		}
	}
}

void count(int size)
{
	SetConsoleCursorPosition(h, { 37, 0 });
	cout << "  ";
	SetConsoleCursorPosition(h, { 37, 0 });
	SetConsoleTextAttribute(h, 10);
	cout << size;
	SetConsoleTextAttribute(h, 7);
}

void clearMenu()
{
	int sLength = 62, fLength = 90, sWidth = 1, fWidth = 10;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });
			cout << " ";
		}
	}
}

void delimetr(short column, short row, int length, int color)
{
	SetConsoleCursorPosition(h, { column,row });
	SetConsoleTextAttribute(h, color);
	for (int i = 0; i < length; i++)
		cout << char(196);
	SetConsoleTextAttribute(h, 7);
}

void redaktFrame()
{
	int sLength = 65, fLength = 100, sWidth = 14, fWidth = 25;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });

			if (i == sWidth || i == fWidth - 1)
				cout << char(178);
			else if (j == sLength && sWidth < i && i < fWidth)
				cout << char(178);
			else if (j == fLength - 1 && sWidth < i && i < fWidth)
				cout << char(178);
		}
	}
}

void cleanRedaktFrame()
{
	int sLength = 65, fLength = 100, sWidth = 14, fWidth = 25;

	for (short i = sWidth; i < fWidth; i++)
	{
		for (short j = sLength; j < fLength; j++)
		{
			SetConsoleCursorPosition(h, { j,i });

			cout << " ";
		}
	}
}

//int len(char **arr, int row)
//{
//	int length = 0;
//	while (arr[row][length] != '\0')
//		length++;
//	return length;
//}

void cleanRedaktPlace()
{
	for (short i = 24; i < 31; i++)
	{
		SetConsoleCursorPosition(h, { 0, i });
		for (int k = 0; k < 50; k++)
			cout << " ";
	}
}

void fillRedaktPlace()
{
	short row = 15, column = 66;

	char names[5][10] = { "Name: ", "Surname: ", "Age: ", "Number: ", "Mail: " };

	for (int i = 0; i < 5; i++)
	{
		SetConsoleCursorPosition(h, { column, row++ });
		cout << names[i];
		if (i != 4)
			delimetr(column, row++, 30, 14);
	}
}

void AddPerson(Person *p, int &size)
{
	redaktFrame();
	fillRedaktPlace();

	short row = 15, col = 75, age = 0;
	char str[50] = {};

	if (str == "13")
		cin.ignore();

	SetConsoleTextAttribute(h, 10);
	SetConsoleCursorPosition(h, { col, row });
	cin.getline(str, 50);
	strcpy(p[size].name, str);
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cin.getline(str, 50);
	strcpy(p[size].surname, str);
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cin >> age;
	p[size].age = age;
	//cin.getline(str, 50);
	//strcpy(p[size].age, str);
	row += 2;
	cin.ignore();

	SetConsoleCursorPosition(h, { col, row });
	cin.getline(str, 50);
	strcpy(p[size].number, str);
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cin.getline(str, 50);
	strcpy(p[size].email, str);

	SetConsoleTextAttribute(h, 7);

	size++;
}

void printSurnameName(Person *arr, int index)
{
	cout << arr[index].surname << " " << arr[index].name;
}

void Print(Person *arr, int size)
{
	short temp = 1;
	clearTable();
	if (size != 0)
		for (short i = 0; i < size; i++)
		{
			SetConsoleCursorPosition(h, { 1, temp * 2 });
			cout << "\t\t\t\t\t\t";
			SetConsoleCursorPosition(h, { 1, temp * 2 });
			cout << i + 1 << ". ";
			printSurnameName(arr, i);
			delimetr(1, temp * 2 + 1, 40, menuColor);
			temp++;
		}
}

void Sort(Person *arr, int size)
{
	Person temp;
	if (size == 1)
		Print(arr, size);
	else
	{
		for (int i = size - 1; i > 0; i--)
		{
			for (int j = 0; arr[i].surname != '\0'; j++)
			{
				if (arr[i].surname < arr[i + 1].surname)
				{
					temp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = temp;
					break;
				}
				else if (arr[i].surname > arr[i + 1].surname)
					break;
			}
		}

		Print(arr, size);
	}
}

void RemoveStudent(Person *p, int &size)
{
	int num = 0;
	Person temp;
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Enter the order number of student for remove: ";
	SetConsoleTextAttribute(h, 10);
	cin >> num;
	SetConsoleTextAttribute(h, 7);
	num--;

	while (true)
	{
		if (num == size - 1 || size == 1)
			break;

		temp = p[num];
		p[num] = p[num + 1];
		p[num + 1] = temp;
		num++;
	}
//	delete[] p;
	size--;
}

void fillPersonData(Person *p, int index)
{
	short row = 15, col = 75;

	SetConsoleTextAttribute(h, 10);
	SetConsoleCursorPosition(h, { col, row });
	cout << p[index].name;
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cout << p[index].surname;
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cout << p[index].age;
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cout << p[index].number;
	row += 2;

	SetConsoleCursorPosition(h, { col, row });
	cout << p[index].email;

	SetConsoleTextAttribute(h, 7);
}

void EditStudent(Person *arr, int size)
{
	cleanRedaktFrame();
	int num = 0, age = 0;
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Enter the order number of student for editing: ";
	SetConsoleTextAttribute(h, 10);
	cin >> num;
	num--;
	int index = num;
	SetConsoleTextAttribute(h, 7);
	cleanRedaktPlace();
	redaktFrame();
	fillRedaktPlace();
	fillPersonData(arr, index);
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Choice number";
	cout << "\n1: Name";
	cout << "\n2: Surname";
	cout << "\n3: Age";
	cout << "\n4: Number";
	cout << "\n5: Email";
	cout << "\nChoice: ";
	int choice;
	SetConsoleTextAttribute(h, 10);
	cin >> choice;
	SetConsoleTextAttribute(h, 7);
	cleanRedaktPlace();
	
	switch (choice)
	{
	case 1:
		cin.ignore();
		SetConsoleCursorPosition(h, { 0, 24 });
		cout << "Input new name : ";
		SetConsoleTextAttribute(h, 10);
		cin.getline(arr[num].name, nameSurname);
		SetConsoleTextAttribute(h, 7);
	break;

	case 2:
		cin.ignore();
		SetConsoleCursorPosition(h, { 0, 24 });
		cout << "Input new surname : ";
		SetConsoleTextAttribute(h, 10);
		cin.getline(arr[num].surname, nameSurname);
		SetConsoleTextAttribute(h, 7);
	break;

	case 3:
		cin.ignore();
		SetConsoleCursorPosition(h, { 0, 24 });
		cout << "Input new age : ";
		SetConsoleTextAttribute(h, 10);
		cin >> age;
		arr[num].age = age;
		SetConsoleTextAttribute(h, 7);
	break;

	case 4:
		cin.ignore();
		SetConsoleCursorPosition(h, { 0, 24 });
		cout << "Input new number : ";
		SetConsoleTextAttribute(h, 10);
		cin.getline(arr[num].number, phoneNumber);
		SetConsoleTextAttribute(h, 7);
	break;

	case 5:
		cin.ignore();
		SetConsoleCursorPosition(h, { 0, 24 });
		cout << "Input new email : ";
		SetConsoleTextAttribute(h, 10);
		cin.getline(arr[num].email, mail);
		SetConsoleTextAttribute(h, 7);
	}
	cleanRedaktPlace();
	redaktFrame();
	fillRedaktPlace();
	fillPersonData(arr, index);
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Redact again?(y/n): ";
	char sym;
	cin >> sym;
	if (sym == 'y')
		EditStudent(arr, size);
	else
	{
		cleanRedaktFrame();
		cleanRedaktPlace();
	}
}

void FindStudent(char **arr, int size)
{
	char *temp = new char[nameLength];
	bool check = true;
	short row = 25;
	SetConsoleCursorPosition(h, { 0, 24 });
	cout << "Enter the name or part of name: ";
	cin.getline(temp, nameLength);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; arr[i][j] != '\0'; j++)
		{
			if (arr[i][j] == temp[0])
			{
				for (int k = 0; temp[k] != '\0'; k++, j++)
				{
					if (arr[i][j] != temp[k])
						check = false;
				}
				if (check)
				{
					SetConsoleCursorPosition(h, { 0, row });
					cout << arr[i];
					row++;
					break;
				}
			}
		}
	}
	cout << endl;
	system("pause");
}

void menu(int size)
{
	static Person *arr = new Person[size];
	int sel = 0, key = 0;
	clearMenu();
	if (size == 0)
		while (true)
		{
			SetConsoleCursorPosition(h, { 72, 2 });

			if (sel == 0)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Add person";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 75, 3 });
			if (sel == 1)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Exit";
			SetConsoleTextAttribute(h, defaultColor);

			key = getch();
			if (key == 224)
				key = getch();

			if (key == 72 && sel == 1) // Up
				sel--;
			else if (key == 80 && sel == 0) // Down
				sel++;
			else if (key == 13 && sel == 0)
			{
				AddPerson(arr, size);
				count(size);
				cleanRedaktFrame();
				Sort(arr, size);
				menu(size);
				break;
			}
			else if (key == 13 && sel == 1)
				break;
		}
	else
		while (true)
		{
			SetConsoleCursorPosition(h, { 72, 2 });

			if (sel == 0)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Add person";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 70, 3 });

			if (sel == 1)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Remove person";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 67, 4 });

			if (sel == 2)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Person modification";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 70, 5 });

			if (sel == 3)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Person search";

			SetConsoleTextAttribute(h, defaultColor);
			SetConsoleCursorPosition(h, { 75, 6 });

			if (sel == 4)
				SetConsoleTextAttribute(h, menuColor);
			cout << "Exit";

			SetConsoleTextAttribute(h, defaultColor);

			key = getch();
			if (key == 224)
				key = getch();

			if (key == 72 && 0 < sel) // Up
				sel--;
			else if (key == 80 && sel < 4) // Down
				sel++;
			else if (key == 13 && sel == 0)
			{
				AddPerson(arr, size);
				count(size);
				cleanRedaktFrame();
				Sort(arr, size);
				menu(size);
				break;
			}
			else if (key == 13 && sel == 1)
			{
				RemoveStudent(arr, size);
				count(size);
				cleanRedaktPlace();
				Print(arr, size);
				menu(size);
				break;
			}
			else if (key == 13 && sel == 2)
			{
				EditStudent(arr, size);
				Print(arr, size);
				menu(size);
				break;
			}
			//else if (key == 13 && sel == 3)
			//{
			//	FindStudent(arr, size);
			//	cleanRedaktPlace();
			//	menu(list, size);
			//	break;
			//}
			else if (key == 13 && sel == 4)
				break;
		}
}
