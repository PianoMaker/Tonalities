#include <iostream>
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


	return alter;
}