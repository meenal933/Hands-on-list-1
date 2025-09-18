/*

 Que_5
 Author: Meenal Hirwani
 Description: Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

Date: August 5, 2025

=======================================================================================================================================================================================   
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

int i=1;
int fd;

for(int j=0; j<5; j++)
{
char name[20];
sprintf(name, "file%dtxt", i);

fd = creat(name, 0644);
i++;

}
while(1)
{

sleep(1);

}

return 0;
}




/*
  OUTPUT
  file1 file2 file3 file4 file5

  ( To check the file descriptor table: ls -l /proc/PID/fd)
  total 0
lrwx------ 1 hp hp 64 Sep 18 16:02 0 -> /dev/pts/1
lrwx------ 1 hp hp 64 Sep 18 16:02 1 -> /dev/pts/1
lrwx------ 1 hp hp 64 Sep 18 16:02 2 -> /dev/pts/1
l-wx------ 1 hp hp 64 Sep 18 16:02 3 -> /home/hp/HANDS_ON1/Que_5/file1txt
l-wx------ 1 hp hp 64 Sep 18 16:02 4 -> /home/hp/HANDS_ON1/Que_5/file2txt
l-wx------ 1 hp hp 64 Sep 18 16:02 5 -> /home/hp/HANDS_ON1/Que_5/file3txt
l-wx------ 1 hp hp 64 Sep 18 16:02 6 -> /home/hp/HANDS_ON1/Que_5/file4txt
l-wx------ 1 hp hp 64 Sep 18 16:02 7 -> /home/hp/HANDS_ON1/Que_5/file5txt

 
*/

