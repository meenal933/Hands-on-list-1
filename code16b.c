/*

  Que_16
  Author: Meenal Hirwani
  Description: Write a program to perform mandatory locking.
  a. Implement write lock
  b. Implement read lock


 Date: August 12, 2025 
=======================================================================================================================================================================================
 
 */


#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
#include <string.h>

int main(){
        struct flock lock;
        int fd;
        fd = open("file16.txt", O_RDONLY); 
        if (fd < 0) 
	{
                perror("Error opening file");
                return 1;
        }


        lock.l_type = F_RDLCK;          //applying read lock
        lock.l_whence = SEEK_SET;       
        lock.l_start = 0;
        lock.l_len = 0;                 
        lock.l_pid = getpid();        

        printf("Before entering CS (Read Lock)\n");
        fcntl(fd, F_SETLKW, &lock);     // Blocking call to acquire read lock
        printf("Inside Critical Section (Read Lock)\n");

        char buffer[100];
        ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
        if (bytes > 0) {
                buffer[bytes] = '\0';
                printf("Read from file: %s\n", buffer);
        } else {
                printf("Nothing to read or error.\n");
        }

        sleep(30);                      

        printf("Enter to Unlock\n");
        getchar();
        printf("Unlocked\n");

        lock.l_type = F_UNLCK;        
        fcntl(fd, F_SETLK, &lock);
        printf("finish\n");

        close(fd);
        return 0;
}


/*
  OUTPUT
 Before entering CS (Read Lock)
 Inside Critical Section (Read Lock)
 Read from file: Hello
 This is the file for execution of question_16.

  
 Enter to Unlock
 Unlocked
 finish
*/
