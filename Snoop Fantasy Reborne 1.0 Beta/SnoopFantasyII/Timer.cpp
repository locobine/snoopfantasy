#include "Timer.h"

Timer::Timer() {
	reset();
	rolando = false;
}

void Timer::reset() 
{
	begin = 0;
	end = 0;
}

void Timer::start() 
{
	begin = clock();
}

void Timer::finish() 
{
	end = clock();
}

void Timer::contaAte(double n)
{
	t = n;
	start();
	rolando = true;
}

bool Timer::checaConta()
{
	finish();
	double e = ((double)(end - begin)) / CLOCKS_PER_SEC;
	if (e / 1 >= t)
	{
		reset();
		rolando = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool Timer::taRolando()
{
	return rolando;
}

double Timer::getElapsedTimeMs() 
{
	double e = ((double)(end - begin)) / CLOCKS_PER_SEC;
	return e;
}