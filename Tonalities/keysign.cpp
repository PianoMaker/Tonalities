#include "Tonalities.h"
int keysign(int step, int alter, bool minor)
{
	int keysign;
	switch (step)
	{
	case DO: keysign = 0; break;
	case RE: keysign = 2; break;
	case MI: keysign = 4; break;
	case FA: keysign = -1; break;
	case SOL: keysign = 1; break;
	case LA: keysign = 3; break;
	case SI: keysign = 5; break;
	default: return 100;
	}
	
	if (alter) keysign += alter*7;
	if (minor) keysign -= 3;
	return keysign;
}
