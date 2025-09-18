/*
 Que_17
 Author : Meenal Hirwani
 Description: Write a program to simulate ticket reservation. Implement write lock
 Write a program to open a file, store a ticket number and exti. Write a seperate program to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
 
Date: August 14, 2025
=======================================================================================================================================================================================
 
 
 */

//INITIALIZING TICKET FILE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>
#include <fcntl.h>

int main()
{
	int ticket_number =1;
	int fd = open ("file17.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd == -1)
	{
		perror("Error: File not found\n");
		return 1;
	}
	else
	{
		printf(" Successful: File Opened\n");
	}

       //initializing ticket number
       if(write(fd,&ticket_number, sizeof(ticket_number))!= sizeof(ticket_number))
       {
	       perror("Error occured during write file");
	       close(fd);
	       return 1;
       }

       printf("Ticket file created with number: %d\n", ticket_number);
       close(fd);
       return 0;
}



/*

  OUTPUT
Successful: File Opened
Ticket file created with number: 1
 
 */
