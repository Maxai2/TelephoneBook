#include <iostream>
//#include <Windows.h>

using namespace std;

#include "Functions.h"
//--------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	int size = 0;
	PERSON *pers = 0;
	//	pers = (PERSON *)calloc(size, sizeof(PERSON));

	char path[_MAX_PATH];
	sprintf(path, "%s%s", getenv("USERPROFILE"), "Desktop//base.dat");
	FILE *f;

	load(f, path, pers, size);

	GotoXY(15, 0);
	cout << "PHONE BOOK | COUNT: ";
	SetColor(10);
	cout << size;

	SetColor(7);
	frame();

	menu(pers, size);

	GotoXY(0, 23);
	cout << endl;

	save(f, path, pers, size);
	if (pers) //size > 0
		free(pers);

	return 0;
}
//--------------------------------------------------------------------------
