/*
 QUE_27e
 Author: Meenal Hirwani
 Description: Write a program to execute ls -Rl by the following system calls.
 e. execvp
 
 Date: August 21, 2025
=======================================================================================================================================================================================

 */

#include <stdio.h>
#include <unistd.h>

int main()
{

        //Using execvp
        printf("executing ls -Rl using execvp\n");
        char*args[] = {"ls","-Rl", NULL};
	execvp("ls", "args");

        perror("execlp Failed");
        return 1;

        
}
