/*
Que_4 using RD_WR
Author : Meenal Hirwani
Description: Write a program to open an existing file with read write mode.

Date: August 5, 2025;

======================================================================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>  //for open()
#include<unistd.h> // for close()

int main()
{
	int fd;
	fd = open("four.txt", O_RDWR);

	if(fd<0)
	{
		perror("File Exist");
	} else
		printf("File created successfully with FD: %d\n",fd);
	close(fd);

}

//OUTPUT
//File created successfully with FD: 3
