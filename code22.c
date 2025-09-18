/*
 
 QUE_22
 Author: Meenal Hirwani
 Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the parent process. check output of the file.

 Date: August 19, 2025 

=======================================================================================================================================================================================
 
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
	int fd;

	//Open the file in write only mode and write append flag
	fd = open("file22.txt", O_WRONLY | O_APPEND);
	if(fd< 0)
	{
		perror("File not found!!");
		return 1;
	}

	//Creating new process
	int newProcess = fork();

	if(newProcess == 0) 
	{
		// this means child process
		char* childWrite = "Child is writing\n";
		write(fd, childWrite, strlen(childWrite));
	       	//NOTE :Here we don't require any lseek since the file is O_APPEND flag,the file ptr automatically moves to the end of file before each write operation

		printf("Child has written.\n");
	} else
	{
		//Parent process
		char* parentWrite = "Parent is Writing\n";

		write(fd, parentWrite, strlen(parentWrite));
		printf("Parent has written.\n");
	}

	close(fd);
		
	return 0;
}


/*
 
   OUTPUT
Parent has written.
Child has written.

 */
