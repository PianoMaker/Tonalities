#include <iostream>
#include "Tonalities.h"
using std::string;

int pitch_to_alter(int step, int pitch)
{
	string notename;
	string noteaccname;
	int alter, standartpitch;
	//cout << "test1 step =" << step << "\n";

	if (step == DO) standartpitch = 0;
	else if (step == RE) standartpitch = 2;
	else if (step == MI) standartpitch = 4;
	else if (step == FA) standartpitch = 5;
	else if (step == SOL) standartpitch = 7;
	else if (step == LA) standartpitch = 9;
	else if (step == SI) standartpitch = 11;
	else return -1;

	alter = pitch - standartpitch;

	if (alter == 11 && standartpitch == 0)
		alter = -1;
	else if (alter == -10 && standartpitch == 11)
		alter = 2;
	else if (alter == 10 && standartpitch == 0)
		alter = -2;
	else if (pitch == 11 && standartpitch == 2)
		alter = -3;


	return alter;
}