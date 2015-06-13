[![Build Status](https://travis-ci.org/mad4j/delays.svg?branch=master)](https://travis-ci.org/mad4j/delays)

# delays
Very simple shell command that delays the execution for a given time.
It may be used to delay the execution of a script, but it should intent for didactical purporses.

## Build
```bash
gcc -Wall delays.cpp -o delays
```

## Usage
```bash
# delays 10 seconds
./delays 10
```

## Source
```c++
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
#include <cstdlib>

#include <unistd.h>


void delay(int seconds) 
{
	struct timespec current;
	clock_gettime(CLOCK_MONOTONIC, &current);

	long threshold;
	threshold = current.tv_sec + seconds;

	while (current.tv_sec < threshold) {

		printf("\rdelays: %7lds", threshold-current.tv_sec);

		sleep(1);
		clock_gettime(CLOCK_MONOTONIC, &current);		
	}
	printf("\n");	
}


int main(int argc, char** argv) 
{

	setbuf(stdout, NULL);

	if (argc != 2) {
		printf("usage: %s <secs>\n", argv[0]);
	}
	
	int seconds;
	seconds = strtol(argv[1], 0, 0);

	delay(seconds);

	return 0;
}
```
