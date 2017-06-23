#pragma once

#define nameSurname 50
#define mail 60
#define phoneNumber 20
//#define ageNumber 3

struct Person
{
	char name[nameSurname];
//	char *name = new char[nameSurname];  
//	char *name = (char*)calloc(nameSurname, sizeof(char));
	char surname[nameSurname] = {};
	//char age[ageNumber];
	int age = 0;
	char number[phoneNumber] = {};
	char email[mail] = {};
};

void frame();
void menu(Person *pers, int size);
