i/*
 
Que_1.a
Author: Meenal Hirwani
Description: Create the following types of files using (ii) system call
a. soft link(symlink) system call

Date: August 5, 2025
=======================================================================================================================================================================================

 */



#include <unistd.h>
#include <stdio.h>

int main() {
    const char *target = "file1";   // The file to link to
    const char *linkname = "Softlink"; // The symbolic link name

    if (symlink(target, linkname) == -1) {
        perror("Error");
        return 1;
    }
  printf("Soft link created successfully %s -> %s\n", linkname, target);
    return 0;}

//OUTPUT
//soft link created successfully
 
