/*

 QUE_19
 Author: Meenal Hirwani
 Description: Write a program to find out time taken to execute getpid system call. Use time stamp counter.
 
Date: August 14, 2025
=======================================================================================================================================================================================

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//function to read the time stamp counter

unsigned long long readTimeStamp() 
{
	unsigned int s, e;  //start and End
	__asm__ volatile("rdtsc": "=a"(s), "=d"(e));
	return ((unsigned long long)e<<32) | s;
}

int main()
{
	unsigned long long s, e;
	pid_t pid;

	//Measure the time before and after the getpid() call
	
	s = readTimeStamp();
	pid = getpid();
	e = readTimeStamp();

	printf("Process ID: %d\n", pid);
	printf("Time Taken to get the pid in clock cycle: %llu\n", e-s);  //llu--> long long unsigned int
        
	return 0;
}

/*

OUTPUT
Process ID: 6256
Time Taked to get the pid in clock cycle: 8614

*/


