#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <string>
#define ESC 27
#define UP 72
#define DOWN 80 //Коды кнопок на клавиатуре
#define ENTER 13

using namespace std;


class Menu
{
public:
	void GoToXY(short x, short y);

	void ConsoleCursorVisible(bool show, short size);

	int MainMenu();

private:
	int active_menu = 0;

	char ch;

};

