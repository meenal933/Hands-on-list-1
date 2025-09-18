/*
 Que_17.b
Author : Meenal Hirwani
Description: Write a program tosimulate ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exti. Write a seperate program to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
 
=======================================================================================================================================================================================
 
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

int main()
{
	int ticket_number;
	int fd = open("file17.txt", O_RDWR );
	if(fd == -1)
	{
		perror("File not found");
		return 1;
	}
	else
	{
		printf("File opened Successfully.\n");
	}

	//applying write lock(Exclusive)
	if(flock(fd, LOCK_EX) == -1)
	{
		perror("Write lock failed");
		close(fd);
	}

	//read current ticket number
	if(read(fd, &ticket_number, sizeof(ticket_number)) != sizeof(ticket_number)){
		perror("Failed reading the ticket number");
		flock(fd, LOCK_UN);
		close(fd);
		return 1;
	}

	printf("Current ticket number: %d\n", ticket_number);
	ticket_number++;
	lseek(fd,0, SEEK_SET);

	if(write(fd,&ticket_number, sizeof(ticket_number)) != sizeof(ticket_number)){
	perror("Failed writing new ticket number");	
	flock(fd, LOCK_UN);
	close(fd);
	return 1;
	}

	//release lock
	flock(fd, LOCK_UN);
	close(fd);

	printf("The new ticket number is: %d\n", ticket_number);
	return 0;
}


/*

OUTPUT
File opened Successfully.
Current ticket number: 1
The new ticket number is: 2

 */
