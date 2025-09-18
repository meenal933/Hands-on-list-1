/*
 QUE_24
 Author: Meenal Hirwani
 Description: Write a program to create an orphan process.
 
 Date: August 19, 2025
=======================================================================================================================================================================================
 */

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();

	if(pid< 0)
	{
		//fork has failed
		perror("Fork Failed");
		return 1;
	}
	else if(pid == 0)
	{
		//This means child process
		sleep(5); // This is done in order to ensure that the Parent terminates first
			  
	        printf(" Child process is now orphan and it's PID is: %d\n", getpid());
			  //When a child process becomes orphan it is adopted by init process which becomes it's new parent
                printf("New parent for child is init and it's PID is: %d\n", getpid());
	}

	else 
	{
		//Parent Process
		
		printf("The parent process is terminating and it's PID is: %d\n", getpid());
	        exit(0);  //parent process exits making the child orphan

	}

	return 0;
}

/*
 
 OUTPUT
The parent process is terminating and it's PID is: 8766
Child process is now orphan and it's PID is: 8767
New parent for child is init and it's PID is: 3542

 */
