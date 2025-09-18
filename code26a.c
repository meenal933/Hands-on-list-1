/*
 QUE_26a
 Author: Meenal Hirwani
 Description: Write a program to execute an executable program.
 a. use some executable program.
 Date: August 21, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Provide full or relative path to the executable

    char *path = "/bin/ls"; //providing full path because using execv
    char *args[] = {"ls", "-l", NULL};

    if (execv(path, args) == -1) {
        perror("execv failed");
        return 1;
    }

    return 0;
}


/*

 OUTPUT
 total 28
-rw-r--r-- 1 hp hp   806 Sep  6 13:19 code26a.c
-rw-rw-r-- 1 hp hp   980 Sep  3 14:16 code26b.c
-rw-rw-r-- 1 hp hp    65 Sep  6 13:21 file26a
-rwxrwxr-x 1 hp hp 16056 Sep  6 13:21 OP


 */
