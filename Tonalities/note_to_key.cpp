//Визначає латинську назву за ступенем і висотою

#include <iostream>;
using namespace std;
enum NOTES3 { DO, RE, MI, FA, SOL, LA, SI };

string note_to_key(int step, int pitch)
{
	string notename;
	string noteaccname;
	int alter, standartpitch;
	//cout << "test1 step =" << step << "\n";
	if (step == -1)
	{
		notename = "--";
	}
	else if (step > 6)
		step -= 7;
	else;
	//cout << "test2 step =" << step << "\n";
	if (step == DO)
	{
		notename = "c"; standartpitch = 0;
	}
	else if (step == RE)
	{
		notename = "d"; standartpitch = 2;
	}
	else if (step == MI)
	{
		notename = "e"; standartpitch = 4;
	}
	else if (step == FA)
	{
		notename = "f"; standartpitch = 5;
	}
	else if (step == SOL)
	{
		notename = "g"; standartpitch = 7;
	}
	else if (step == LA)
	{
		notename = "a"; standartpitch = 9;
	}
	else if (step == SI)
	{
		notename = "h"; standartpitch = 11;
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	alter = pitch - standartpitch;
	if (alter == 11) alter = -1;
	if (alter == 0)
		noteaccname = "";
	else if (step == SI && pitch == 0)
	{
		notename = "h"; noteaccname = "is";
	}
	else if (step == DO && pitch == 11)
	{
		notename = "c"; noteaccname = "es";
	}

	else if (alter == 2)
	{
		noteaccname = "isis";
	}
	else if (alter == -2)
	{
		noteaccname = "eses";
	}
	else if (alter == 1)
	{
		noteaccname = "is";
	}
	else if (alter == -1)
	{
		noteaccname = "es";
	}

	else
	{
		return "Помилка при введенні ноти\n";
	}

	string key_to_notename(notename + noteaccname);

	if (key_to_notename == "hes") key_to_notename = "b";
	if (key_to_notename == "heses") key_to_notename = "bes";
	if (key_to_notename == "ees") key_to_notename = "es";
	if (key_to_notename == "aes") key_to_notename = "as";
	return key_to_notename;
}