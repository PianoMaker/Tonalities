#include<iostream>
#include"messages.h"
using namespace std;

bool Trigger(string text) // захист від випадково невірно введенних символів для змінної bool
{
	char choice[3];
	Message(standart, text);
	while (true)
	{
		if (cin.rdbuf()->in_avail() > 0) { cin.clear(); cin.ignore(INT_MAX, '\n'); }
		cin.getline(choice, 3);
		if (strcmp(choice, "1") == 0) return true;
		else if (strcmp(choice, "0") == 0) return false;
		else Message(red,"try once more! 1 or 0!\n");
	}
}