/*
 QUE_27b
 Author: Meenal Hirwani
 Description: Write a program to execute ls -Rl by the following system calls.
 b. execlp
 
Date: August 21, 2025
=======================================================================================================================================================================================

 */

#include <stdio.h>
#include <unistd.h>

int main()
{

        //Using excelp
        printf("executing ls -RL using execv\n");
        char*args[] = {"ls", "-RL", NULL};
	execv("./27ex", args);
        
	perror("execv Failed");
        return 1;

        return 0;
}
                                  
