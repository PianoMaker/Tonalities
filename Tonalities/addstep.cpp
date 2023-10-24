
#include <iostream>;
// обчислює ступінь після додаання заданого інтервалу (в ступенях)
int addstep(int step1, int step2)
{
	int step = step1 + step2;
	while (step < 0) step += 7;
	while (step > 6) step -= 7;
	return step;
}