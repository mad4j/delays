

/**
 * delays
 * Copyright (c) 2015 Daniele Olmisani
 * 
 * see LICENSE file
 *
 * Compile using: gcc -Wall delays.cpp -o delays
 */ 

#include <cstdio>
#include <ctime>

#include <unistd.h>


void delay(int seconds) 
{
	struct timespec current;
	clock_gettime(CLOCK_MONOTONIC, &current);

	long threshold;
	threshold = current.tv_sec + seconds;

	while (current.tv_sec < threshold) {

		printf("\rdelays: %5lds", threshold-current.tv_sec);

		sleep(1);
		clock_gettime(CLOCK_MONOTONIC, &current);		
	}
	printf("\n");	
}


int main(int argc, char** argv) 
{

	setbuf(stdout, NULL);
	
	delay(10);

	return 0;
}
