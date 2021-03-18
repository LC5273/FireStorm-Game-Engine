#pragma once

#if 1 //windows macro define
	#include <Windows.h>
#endif

#include <stdint.h>

class Timer
{
private:
	LARGE_INTEGER start;
	double Frequency;

public:
	Timer() {
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		Frequency = 1.0f / frequency.QuadPart;
		QueryPerformanceCounter(&start);
	}

	void reset() {
		QueryPerformanceCounter(&start);
	}

	float elapsed() {
		LARGE_INTEGER current;
		QueryPerformanceCounter(&current);
		uint64_t cycles = current.QuadPart - start.QuadPart;
		//start = current;
		return (float)(cycles * Frequency);
	}
};

