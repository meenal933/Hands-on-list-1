/*
 QUE_23
 Author: Meenal Hirwani
 Description: Write a program to create a Zombie state of the running program.

 Date: August 19, 2025
========================================================================================================================================================================================
 
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();

	if(pid< 0)
	{
		//fork failed
		perror("Fork Failed");
		return 1;
	}

	else if(pid ==0)
	{
		//Child Process
		printf("The child process with pid = %d is exiting\n", getpid());
		exit(0);

		//This make the child process a zombie since it has terminated but the parent hasn't called 'wait()' to clean up the process entry

	}

	else
	{
		//Parent Process
		printf("Parent process with pid = %d is sleeping \n", getpid());
		sleep(30);  //Sleep for 30 sec to keep the parent alive
			   
		printf("Parent process is exiting now\n");
	}

	return 0;
}

/*
 OUTPUT
Parent process with pid = 8615 is sleeping 
The child process with pid = 8616 is exiting
Parent process is exiting now
  
 */

//NOTE : we can also check the current status of the zombue command using --> ps aux | grep z


