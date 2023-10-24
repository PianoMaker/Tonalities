#include <iostream>
#include "Tonalities.h"
#pragma warning(disable:4996)
using namespace std;


Tonalities::Tonalities(string msg, int notation)
{
	bool mistake;
	string name;
	do
	{
		mistake = false;
		name = Enter(mistake, msg, notation);
		if (mistake) cout << "incorrect tonality, try again" << endl;
	} while (mistake);
	char* temp = new char[name.length() + 1];
	strcpy(temp, name.c_str());
	this->name = name;
	key = strtok(temp, "-");
	char *token = strtok(NULL, " ");
	if (token) mode = token;
	if (mode == "-dur") mode = "dur";
	step = key_to_step(key, notation);
	pitch = key_to_pitch(key, notation);
	alteration = pitch_to_alter(step, pitch);
	if (mode == "dur") minor = 0;
	else  minor = 1;
	keysignatures = keysign(step, alteration, minor);
	if (!minor)this->name[0] = toupper(name[0]);
}

void Tonalities::Show()
{
	cout << name << ", step = " << step << ", keys = " << keysignatures << endl;
}

void Tonalities::ShowName()
{
	cout << name;
}

void Tonalities::ShowInBrackets()
{
	cout << "(" << name << ")";
}



bool Tonalities::equal(Tonalities destination)
{
	if (keysignatures == destination.keysignatures && pitch == destination.pitch)
		return true;
	else return false;
}

bool Tonalities::relative(Tonalities destination)
{
	if (keysignatures == destination.keysignatures && step != destination.step)
		return true;
	else if (keysignatures == destination.keysignatures + 1 || keysignatures == destination.keysignatures - 1)
		return true;
	else if (minor == true && destination.minor == false && destination.keysignatures == keysignatures + 4)
		return true;
	else if (minor == false && destination.minor == true && destination.keysignatures == keysignatures - 4)
		return true;
	else return false;
}

void Tonalities::recount()
{
	key = note_to_key(step, pitch);
	alteration = pitch_to_alter(step, pitch);
	keysignatures = keysign(step, alteration, minor);
	if (minor) mode = "moll";
	else mode = "dur";
	name = key + "-" + mode;
	if (!minor)name[0] = toupper(name[0]);
}

void Tonalities::transport(int model)
{
	switch (model)
	{
	default: return;
	case 2:   /* II/VII ступінь */
		if (!minor) { step = addstep(step, 1); pitch = addpitch(pitch, 2);  minor = true; }
		else { step = addstep(step, -1); pitch = addpitch(pitch, -2);  minor = false; }
		break;
	case 3: step = addstep(step, 2); /* III ступінь */
		if (!minor) { pitch = addpitch(pitch, 4); minor = true; }
		else { pitch = addpitch(pitch, 3); minor = false; };
		break;
	case 4: step = addstep(step, 3); pitch = addpitch(pitch, 5); break;// субдомінанта
	case 5: step = addstep(step, 4); pitch = addpitch(pitch, 7); break; // домінанта
	case 6: step = addstep(step, 5); /* VI ступінь */
		if (!minor) { pitch = addpitch(pitch, 9); minor = true; }
		else { pitch = addpitch(pitch, 8); minor = false; }
		break;
	case 1: if (minor) { step = addstep(step, 4); pitch = addpitch(pitch, 7);  minor = false; } // мажорна домінанта
		  else { step = addstep(step, 3); pitch = addpitch(pitch, 5); minor = true; } // мінорна субдомінанта
		  break;
	};
	recount();
}

void Tonalities::enharmonize()
{
	if (keysignatures > 0)
	{
		step = addstep(step, 1); recount();
	}
	else 
	{
		step = addstep(step, -1); recount();
	}

}



void Tonalities::ShowRelatives()
{
	Tonalities current = *this;
	for (int i = 1; i < 7; i++)
	{
		current.transport(i);
		current.Show();
		current = *this;
	}
}


	




