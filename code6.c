/*

 Que_6
 Author: Meenal Hirwani
 Description: Write a program to take input from STDIN and display on STDOUT. use read/write system calls. 

 Date: August 7, 2025 
=======================================================================================================================================================================================   
*/


#include<stdio.h> //for perror
#include<unistd.h> // for read() and write()

#define buffer_size 1024

int main(){
	char buffer[buffer_size];
	int bytesread;
	
	//read from STDIN
	bytesread = read(0,buffer,buffer_size); //fd value for read is 0
	
	if(bytesread<0){
		perror("Error reading from STDIN");
		return 1;
	}
	
	//write output to STDOUT
	int bytesWritten = write(1,buffer,bytesread); // indicates the number of bytes to write
	
	if(bytesWritten < 0){
		perror("Error writing to STDOUT");
		return 1;
	}
	return 0;
}


//OUTPUT
//MEENAL HIRWANI 
//MEENAL HIRWANI
// (The content we write will get printed on the screen )
//
