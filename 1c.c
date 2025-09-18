/*
 
Que_1.c
Author: Meenal Hirwani
Description: Create the following types of files using (ii) system call
c. FIFO(mkfifo library Function or mknod system call)

Date: August 5, 2025
=======================================================================================================================================================================================

 */



#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {

        int msg = mkfifo("LINK", 0666);
        if(!msg) printf("Successful: FIFO file created!!");
        else{
                printf("Unsuccessful: Creation failed");
                return 1;
        }

        return 0;
}




//OUTPUT
//Successful: FIFO file created!!
