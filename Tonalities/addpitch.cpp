#include <iostream>;
// обчислює висоту звуку після додаання заданого інтервалу (в півнтоах)
int addpitch(int pitch1, int pitch2)
{
	int pitch = pitch1 + pitch2;
	while (pitch < 0) pitch += 12;
	while (pitch > 11) pitch -= 12;
	return pitch;
}