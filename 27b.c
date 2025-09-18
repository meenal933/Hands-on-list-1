/*
QUE_27b
Author: Meenal Hirwani
Description: Write a program to execute ls-Rl by the following system calls
b. execlp

Date: August 21, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
        //first we created an executable file called 27ex.c


        //using execlp
        printf("Executing ls-Rl using execlp\n");
        execlp("./27ex.c", "ls", "-Rl", NULL);
        perror("execlp failed!!"); //will be printed if execlp fails
        return 1;
        
        return 0;
}       

