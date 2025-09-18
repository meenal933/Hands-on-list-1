/*
 
Que_1.b
Author: Meenal Hirwani
Description: Create the following types of files using (ii) system call
b. hard link(link system call)

Date: August 5, 2025
=======================================================================================================================================================================================

 */




#include <stdio.h>
#include <unistd.h>

int main()
{
        const char *target = "file2"; //The file to link to
        const char *pathname = "hardlink"; //The hardlink to be created


      

        if(link (target, linkpath )== -1){
                perror("Error");
		return 1;
        }
       
      
                printf("Hard link created successfully!!  %s -> %s \n ", pathname , target);
       
        return 0;
}


//OUTPUT
//hard link created successfully 
