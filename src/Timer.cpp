#include <iostream>
#include <cstdlib>
#include <sys/time.h>

#include "Timer.h"

Timer::Timer(){
	gettimeofday(&startTime, NULL);
}

double Timer::elapsed(){
	gettimeofday(&endTime, NULL);
	
	double elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1000.0;
	elapsedTime += (endTime.tv_usec - startTime.tv_usec) / 1000.0;

	return elapsedTime;
}
