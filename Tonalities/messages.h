#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum COLORS { olive = 6, standart = 7, gray = 8, lightgreen = 10, green = 11, red = 12, yellow = 14 };

void inline Color(COLORS color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void inline  Line(COLORS color)
{
	Color(color);
	cout << setw(50) << setfill('-') << "" << endl;
	Color(standart);
}

/*кольорове повідомлення*/
void inline  Message(COLORS color, string txt)
{

	Color(color);
	cout << txt;
	Color(standart);
}

void inline  WrongChoice()
{
	Message(olive, "невірний вибір, спробуйте ще раз\n");
}

void inline Header(string text)
{
	Color(green);
	Message(green, text);
	Color(standart);
}


