/*
  Que_12
  Author: Meenal Hirwani
  Description: Write a program to find out the opening mode of a file. Use fcntl.
    
  Date: August 12, 2025
=======================================================================================================================================================================================


*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
	FILE *file = fopen("file12.txt", "r");   //opens file in read only mode and sets up a pointer that points to first char in it 
	
        int fd = fileno(file); //return integer fd of the input stream
	int mode = fcntl(fd, F_GETFL); //return(as the function result) the file access mode and the file status flags

         printf("Mode of fd is: %d\n", mode);
	 return 0;

}

//OUTPUT
//Mode of fd is: 32768

        		
