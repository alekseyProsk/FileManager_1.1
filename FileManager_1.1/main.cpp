#include<iostream>
#include"Menu.h"
#include"FileSystem.h"



using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Menu m;
	m.MainMenu();
	/*FileSystem h("c"s);
	h.getDiskInfo();*/

	return 0;

}
