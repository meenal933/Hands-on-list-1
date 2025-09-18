
/*
   Que_9
   Author: Meenal Hirwani
   Description: Write a program to print the following information about a given file:
   a).Inode 
   b).number of hard links 
   c).uid  
   d).gid 
   e).size 
   f).block size 
   g).number of blocks 
   h).time of last access 
   i).time of last modification 
   j).time of last change
   
Date: August 7, 2025

=======================================================================================================================================================================================
*/



#include<stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    struct stat sb;
    
    if (argc != 2) {
        printf("Usage: %s file_stat\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if(stat(argv[1], &sb) == -1)
    {
	    //checking whether the structure has been filled with file info or not
	    perror("Stat failed");
	    exit(EXIT_FAILURE);
    }
      
    //Print all the information of file

    printf("File Name is: %s\n", argv[1]);
    printf("a. Inode: %ld\n", (long)sb.st_ino);
    printf("b. Number of hard links: %ld\n", (long) sb.st_nlink);
    printf("c. UID: %ld\n", (long)sb.st_uid);
    printf("d. GID: %ld\n", (long)sb.st_gid);
    printf("e. Size: %lld bytes\n", (long long) sb.st_size);
    printf("f. Block size: %ld\n", (long) sb.st_blksize);
    printf("g. Number of blocks: %lld\n", (long long)sb.st_blocks);
    printf("h. Last access time: %s", ctime(&sb.st_atime));
    printf("i. Last modification time: %s", ctime(&sb.st_mtime));
    printf("j. Last status change time: %s", ctime(&sb.st_ctime));
    
    exit(EXIT_SUCCESS);
}


//OUTPUT
/*

    File Name is: file_stat
a). Inode: 1969924
b). Number of hard links: 1
c). UID: 1000
d). GID: 1000
e). Size: 75 bytes
f). Block size: 4096
g). Number of blocks: 8
h). Last access time: Fri Aug 22 00:58:49 2025
i). Last modification time: Fri Aug 22 00:50:14 2025
j). Last status change time: Fri Aug 22 00:50:14 2025

*/
