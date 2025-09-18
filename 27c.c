/*
 QUE_27c
 Author: Meenal Hirwani
 Description: Write a program to execute ls -Rl by the following system calls.
 c. execle
 
Date: August 21, 2025
=======================================================================================================================================================================================

 */

#include <stdio.h>
#include <unistd.h>

int main()
{

        //Using excele
        printf("executing ls -RL using execle\n");
        execle("ls","ls","-RL", NULL);
        perror("execle Failed");
        return 1;

        return 0;
}                                  
