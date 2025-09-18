/*

 QUE_21
 Author: Meenal Hirwani
 Description: Write a program, call fork and print the parent and child process id.

 Date: August 19, 2025
=====================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	pid_t pid;
	//create new process
	pid = fork();

	if(pid<0)
	{
		//this means fork failed
		perror("Fork Failed");
		return 1;

	}
	else if(pid == 0)
	{
           //this means child process
	   printf("This is child process and it's PID is: %d\n", getpid());
	   printf("Parent PID(from child) is: %d\n", getpid());
	}

	else
         {   	//if we're in this block means it is parent process
		printf("This is parent process and the PID is: %d\n", getpid());
	        printf("child PID(from parent) is: %d\n", pid);
	 }
	return 0;
}

/*
 
   OUTPUT
   This is parent process and the PID is: 6599
   child PID(from parent) is: 6600
   This is child process and it's PID is: 6600
   Parent PID(from child) is: 6600

 
 */

