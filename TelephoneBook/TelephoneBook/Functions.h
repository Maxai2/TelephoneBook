//#ifndef FUNCTIONS_H
//#define FUNCTIONS_H
#pragma once
//--------------------------------------------------------------------------
#define nameSurname 50
#define mail 60
#define phoneNumber 20
//#define ageNumber 3
//--------------------------------------------------------------------------
typedef struct Person
{
	char name[nameSurname];
	//	char *name = new char[nameSurname];
	//	char *name = (char*)calloc(nameSurname, sizeof(char));
	char surname[nameSurname];
	//char age[ageNumber];
	int age;
	char number[phoneNumber];
	char email[mail];
//	Person * p;
}
PERSON;
//--------------------------------------------------------------------------
void GotoXY(int c, int r);
void SetColor(int color);
void frame();
void menu(PERSON *pers, int size);
//--------------------------------------------------------------------------
//#endif

