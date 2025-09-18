/*
 QUE_27a
 Author: Meenal Hirwani
 Description: Write a program to execute ls-Rl by the following system calls
 a. execl
 
 Date: August 21, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
	//first we created an executable file called 27ex.c
	

	//using execl
	printf("Executing ls-Rl using execl\n");
	execl("./27ex.c", "ls", "-Rl", NULL);
	perror("execl failed!!"); //will be printed if execl fails
	return 1;

	return 0;
}

