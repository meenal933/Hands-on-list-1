/*
 QUE_25
 Author: Meenal Hirwani
 Description: Write a program to create three child processes. The parent should wait for a particular child.(use waitpid system call) 

 Date: August 21, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>


int main()
{
	int status;
	pid_t pid1, pid2, pid3;

	//First child process
	pid1 = fork();
	if(pid1 == -1)
	{
		printf("Fork Failed for pid1\n");
		exit(1);
	} else if(pid1 ==0)
	{
		//child process1

		printf("Child Process1(PID: %d)\n ", getpid());
		exit(0); //child exits
	}


	//Second child process
        pid2 = fork();
        if(pid2 == -1)
        {
                printf("Fork Failed for pid2\n");
                exit(1);
        } else if(pid2 ==0)
        {
                //child process2

                sleep(5); //sleep for 5 sec to simulate work
		printf("Child Process2(PID: %d)\n ", getpid());
                exit(0); //child exits
        }


	//Third child process
        pid3 = fork();
        if(pid3 == -1)
        {
                printf("Fork Failed for pid3\n");
                exit(1);
        } else if(pid3 ==0)
        {
                //child process3

                printf("Child Process3(PID: %d)\n ", getpid());
                exit(0); //child exits
        }

	//Parent Process: wait for the specific child process(pid2) to exit
	printf("Parent(PID: %d) waiting for PID %d to finish...\n", getpid(), pid2);
	
	pid_t waited_pid = waitpid(pid2, &status, 0); //waitpid() suspends the calling process until the system gets info on the child

	if(waited_pid == -1)
	{
		perror("Waitpid error");

	}
	else
	{
		if(WIFEXITED(status)) //wait pid exit status
		{
			printf("Parent: Child with PID %d exited with status %d\n", waited_pid,WEXITSTATUS(status));
		}
		else
		{
			printf("Parent: Child with PID %d did not exit normally\n", waited_pid);
		}
	}
	return 0;
}


/*
 
   OUTPUT
   Parent(PID: 9125) waiting for PID 9127 to finish...
 Child Process1(PID: 9126)
 Child Process3(PID: 9128)

 Child Process2(PID: 9127)
 Parent: Child with PID 9127 exited with status 0

 
 */
