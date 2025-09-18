/*

 Que_
 Author: Meenal Hirwani
 Description: Write a simple program to create a file and print the file descriptor value. use creat() system call.
 
Date: August 5, 2025
=======================================================================================================================================================================================   
*/


#include<stdio.h>
#include<fcntl.h> // for create 
#include<unistd.h> //for close
int main()
{
	int fd;
	fd=creat("Despo", 0644); //create a file with read and write permission for user

		if (fd == -1)
		{
			perror("creat"); // prints error if file not created.
			return 1;
		}
	printf("File created successfully. File Descriptor: %d \n", fd);

	close (fd); //always close the file descriptor
      return 0;
}

/* 
OUTPUT

File created successfully. File Descriptor: 3

(for all first file it will show the fd value 3, because first three values are reserved (0-> stdin, 1->stdout, 2->stderr)

*/

