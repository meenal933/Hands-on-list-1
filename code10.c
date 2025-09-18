/*
  Que_10
  Author:Meenal Hirwani
  Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by bytes(use lseek) and write again 10 bytes.
  a. check the return value of lseek
  b. open the file with od and check the empty spaces in between the data.

  Date: August 7, 2025
=======================================================================================================================================================================================

*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int fd = open("file10.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

	if(fd == -1)
	{
		perror("File not found");
		return 1;
	}

	//Taking the first 10 bytes
	
	const char* c1 = "1234567890";
	int bytesWritten = write(fd, c1,strlen(c1));

	if((bytesWritten != strlen(c1)))
	{
	  perror("Error writing first 10 bytes");
	  close(fd);

	}

	long int index = lseek(fd, 10, SEEK_CUR); //Move current seek forward by 10 bytes
	if(index == -1)
	{
         perror("Error seekin");
  	 close(fd);
         return 1;
        }

         const char* c2 = "Meenal Hirwani";
 	 bytesWritten = write(fd, c2, strlen(c2));
         if(bytesWritten == -1)
	 {
           perror("Error Writing!!");
           close(fd);
           return 1;
	 }
         
         close(fd);
         printf("lseek returned index: %ld\n", index );
         return 0;
}



//  OUTPUT 
// a).  lseek returned index :20


/* 
 b). opening the file with od to check the empty spaces
    use command: od -c file10.txt
    0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   M   e   e   n   a   l       H   i   r   w   a
0000040   n   i
0000042


*/
   

