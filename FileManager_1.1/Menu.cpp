#include "Menu.h"
#include"FileSystem.h"
#include"Create.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu::GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void Menu::ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяем видимост курсора
	structCursorInfo.dwSize = size; // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int Menu::MainMenu()
{

	SetConsoleTitle(L"FileManager_1.1");
	system("CLS");
	setlocale(0, "ru");

	ConsoleCursorVisible(false, 100);
	/*CONSOLE_FONT_INFOEX fontInfo;
	GetCurrentConsoleFontEx(hStdOut, TRUE, &fontInfo);*/ // Получить текущий шрифт
	GoToXY(50, 13);

	string MENU[] = { "Создать файл/ папку", "Удалить файл/папку", "Переименовать файл/папку",
	"Копировать/Перенести файл/папку", "Узнать размер файла", "Получить информацию по диску" };

	string sshortMenu[] = { "Создать файл", "Создать папку" };
	string sshortCpy[] = { "Переименовать", "Копировать", "Переместить"};
	
	Create c; // Создаем Объект для махинаций в функциях меню
	
	int c0 = 0;//switch(c0)
	int c3 = 0;//switch(c3)

	while (true)
	{
		int x = 50, y = 12;
		GoToXY(x, y);
		for (int i = 0; i < size(MENU); i++)
		{
			if (i == active_menu)
				SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
					FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);

			GoToXY(x, y++);
			cout << MENU[i] << endl;

		}
		GoToXY(50, 13);
		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case  ESC:
			exit(0);
		case UP:
		{
			if (active_menu > 0)
				--active_menu;
			break;
		}
		case DOWN:
		{
			if (active_menu < size(MENU) - 1)
				++active_menu;
			break;
		}
		case ENTER:
		{

			switch (active_menu)
			{
			case 0:
			{
				bool flag = true;
				system("CLS");
				while (flag)
				{
					int x = 50, y = 12;
					GoToXY(x, y);

					for (int i = 0; i < size(sshortMenu); i++)
					{
						if (i == c0)
							SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
								FOREGROUND_INTENSITY);
						else SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);

						GoToXY(x, y++);
						cout << sshortMenu[i] << endl;
					}
					char ch1;
					ch1 = _getch();
					if (ch1 == -32) ch1 = _getch(); // Отлавливаем стрелочки
					switch (ch1)
					{
					case  ESC:
						flag = false;
					case UP:
					{
						if (c0 > 0)
							--c0;
						break;
					}
					case DOWN:
					{
						if (c0 < size(sshortMenu) - 1)
							++c0;
						break;
					}

					case ENTER:
					{

						switch (c0)
						{
						case 0:
						{
							system("CLS");
							GoToXY(x, y);
							SetConsoleTextAttribute(hStdOut, FOREGROUND_RED |
								FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							c.createFile();
							_getch();
							system("CLS");
							break;
						}
						case 1:
						{
							system("CLS");
							GoToXY(x, y);
							SetConsoleTextAttribute(hStdOut, FOREGROUND_RED |
								FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							c.createDirectory();
							_getch();
							system("CLS");
							break;
						}
						default:
							sshortMenu;
						}//switch(c0)
					}//enter

					}//switch(ch1)
					system("CLS");
				}//while
				
				_getch();
				system("CLS");
				break;
			}//case 0;
		case 1:
		{
			system("CLS");
			GoToXY(x, y);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			c.Remove();
			_getch();
			system("CLS");
			break;
		}
		case 2:
		{
			system("CLS");
			GoToXY(x, y);
			bool what = true;
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			c.Rename(what);
			_getch();
			system("CLS");
			break;

		}
		case 3:
		{
			bool flag = true;
			bool what = true;
			system("CLS");
			while (flag)
			{
				
				int x = 50, y = 12;
				GoToXY(x, y);


				for (int i = 0; i < size(sshortCpy); i++)
				{
					if (i == c3)
						SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
							FOREGROUND_INTENSITY);
					else SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);

					GoToXY(x, y++);
					cout << sshortCpy[i] << endl;
				}
				char ch2;
				ch2 = _getch();
				if (ch2 == -32) ch2 = _getch(); // Отлавливаем стрелочки
				switch (ch2)
				{
				case  ESC:
					flag = false;
				case UP:
				{
					if (c3 > 0)
						--c3;
					break;
				}
				case DOWN:
				{
					if (c3 < size(sshortCpy) - 1)
						++c3;
					break;
				}

				case ENTER:
				{
					switch (c3)
					{

					case 0:
					{
						system("CLS");
						GoToXY(x, y);

						SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 
							FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						c.Rename(what);
						_getch();
						system("CLS");
						break;
					}
					case 1:
					{
						system("CLS");
						GoToXY(x, y);
						SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 
							FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						c.Copy();
						_getch();
						system("CLS");
						break;
					}
					case 2:
					{
						system("CLS");
						GoToXY(x, y);
						what = false;
						SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 
							FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						c.Rename(what);
						_getch();
						system("CLS");
						break;
					}
					default:
						sshortCpy;

					}//switch(c3)


				}//Enter
				}//switch(ch2)
				system("CLS");
			}//while
			
			_getch();
			system("CLS");
			break;
		}//case 3
		case 4:
		{
			system("CLS");
			GoToXY(x, y);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 
				FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			c.getSize();
			_getch();
			system("CLS");
			break;
		}
		case 5:
		{
			system("CLS");
			GoToXY(x, y);
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 
				FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			string NAMEDisk;
			cout << "Введите букву диска " << endl;
			getline(cin, NAMEDisk);
			FileSystem d(NAMEDisk);
			d.getDiskInfo();
			_getch();
			system("CLS");
			break;
		}

		default:
			active_menu;
		}//switch(active_menu)
		}//ENTER


		}//switch(ch)
	}//while
	return 0;
}


