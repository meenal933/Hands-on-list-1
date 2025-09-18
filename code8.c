/*

  Que_8 
  Author : Meenal Hirwani
  Description : Write a program to open a file in read only mode , read line by line and display each line as it is read. close the file when end of file is reached.
 
  Date: August 7, 2025
=======================================================================================================================================================================================

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define buffersize 1024

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		//check number of arguments provided

		printf("Usage: %sfile8.txt\n", argv[0]);
		return 1;
	}

	//Open file in read only mode
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("Error opening file");
		return 1;
	}

	char buffer[buffersize];
	int bytesRead;
	int i;

	//Read the file line by line
	
	while((bytesRead = read(fd,buffer, buffersize)) > 0)
	{
		if(write(STDOUT_FILENO, buffer, bytesRead) != bytesRead)
		{ 
			perror("unsuccessful: Error writing to stdout");
			close(fd);
			return 1;
		}

	}
	
	if(bytesRead< 0)
	{
		perror("Error reading file ");
		close(fd);
		return 1;
	}

	close(fd); //close the fd

		return 0;
}





//OUTPUT
//This is a test file for Q_8 to read line by line.
//It has multiple lines.

