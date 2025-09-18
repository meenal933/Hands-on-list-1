/*

 Que_3
 Author: Meenal Hirwani
 Description: Write a program to open an existing file with read write mode. try O_EXCL flag also.

 Using EXCL flag
 Date: August 5, 2025
=======================================================================================================================================================================================   
*/



#include<stdio.h>
#include<fcntl.h>  //for open()
#include<unistd.h> // for close()

int main()
{
	int fd;
	fd = open("four.txt", O_CREAT | O_EXCL | O_RDWR, 0644); //O_CREAT and O_EXCL ovoid overwriting the file

	if(fd<0)
	{
		perror("Error: Unsuccessful EXCL");
	}
       	else 
	{  
		printf("Successful: File created with FD: %d\n",fd);
	close(fd);
	} 
	return 0;

}


//OUTPUT
//Successful: File created with FD: 3
