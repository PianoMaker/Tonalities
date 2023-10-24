#include"Tonalities.h"
#include"messages.h"
#define MISTAKE { mistake = true; return "0";}


string Enter(bool& mistake, string msg, int notation)
{
	string tonality;
	Header(msg + "\n");
	cin >> tonality;
	if (tonality.length() < 4)
		MISTAKE;
	for (int i = 0; i < tonality.length(); i++)
		tonality[i] = tolower(tonality[i]);
	if (tonality.substr(tonality.length() - 3) != "dur"
		&& tonality.substr(tonality.length() - 4) != "moll")
		MISTAKE;
	if (tonality.substr(tonality.length() - 3) == "dur"
		&& tonality.substr(tonality.length() - 4, tonality.length() - 4) != "-")
		tonality.insert(tonality.length() - 3, "-");
	if (tonality.substr(tonality.length() - 4) == "moll"
		&& tonality.substr(tonality.length() - 5, tonality.length() - 5) != "-")
		tonality.insert(tonality.length() - 4, "-");
	if (tonality[2] == '-' && tonality[3] == '-')tonality.erase(3, 1);
	if (tonality[3] == '-' && tonality[4] == '-')tonality.erase(3, 1);
	if ((key_to_step(tonality.substr(0, 1), notation) == -100) &&
		(key_to_step(tonality.substr(0, 2), notation) == -100) &&
		(key_to_step(tonality.substr(0, 3), notation) == -100))
		MISTAKE;


	return tonality;
}

