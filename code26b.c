/*
 QUE_26b
 Author: Meenal Hirwani
 Description : Write a program to execute an executable program.
 b). Pass some input to an executable program. (for example excute an executable of ./a.out name)

 Date: August 21, 2025
======================================================================================================================================================================================= 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
	{
		//specify the path to the executable program
		char* path = "./OP_a";

		//pass the arguments to the OP
		char* args[] = {path, "Meenal", NULL};

		//executing the program with the given arguments
		printf("Executing %s with input \n", path);
		execv(path, args); //execute the program file26a with argv getting the arguments from args

		//if execv returns it means it has failed 
		perror("execv failed");
		return 1;
	}


/*
 Executing ./OP_a with input 
 Hello Meenal
 
 */


