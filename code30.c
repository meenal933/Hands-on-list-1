/*
 QUE_30
 Author: Meenal Hirwani
 Description: Write a program to run a script at a specific time using a daemon process.

Date: August 26, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("Fork Failed");
		return 1;
	}

	if(pid == 0)
	{
		 //Child process
		 sleep(10); //give some time for parent process to exit

		 printf("creating the new session with setsid()\n");
		 pid_t newSes = setsid(); //Create a new session
	         
		 if(newSes == -1)
		 {
			 printf("Creating the new session Failed\n");
			 return 1;
		 }else
		 {
			 //Successful creation
			 printf("A new session Created Successfully\n");
		 }
		 int changeDir = chdir("/"); //change the working directory to "/"

		 if(changeDir == -1)
		 {
			 //if chdir fails
			 printf("Trying to change the directory failed\n");
			 return 1;
		 }
		 else
		 {
			 printf("Changed the directory to '/' \n");

			 while(1)
			 {
				 sleep(2); //sleep for 2 sec
				printf("Process id of process is: %d\n", getpid()); // print process id

				printf("The Daemon process is running \n"); //indicates that the daemon is running
			 }
		 }
	}
          
	else
	{
		//PARENT PROCESS
		printf("Parent Process: This is going to exit\n");
		exit(0);
		//parent process exits leaving the child process running
	}
}


//OUTPUT
//Parent process: This is going to exit

/*
 
 
creating the new session with setsid()
A new session Created Successfully
Changed the directory to '/' 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
Process id of process is: 6771
The Daemon process is running 
..
.
.
.

*/
