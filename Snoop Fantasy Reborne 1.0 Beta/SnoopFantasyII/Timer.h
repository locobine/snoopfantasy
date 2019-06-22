#pragma once

#include <time.h>

class Timer {
public:
	Timer();
	void start();
	void finish();
	void reset();
	double getElapsedTimeMs();
	void contaAte(double n);
	bool checaConta();
	bool taRolando();
private:
	clock_t begin, end;
	double t;
	bool rolando;
};

