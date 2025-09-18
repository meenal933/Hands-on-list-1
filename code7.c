

/* 
  Que_7 
  Author: Meenal Hirwani
  Description:  Write a program to copy file1 into file2.
  
  Date: August 7, 2025
======================================================================================================================================================================================

*/



#include<unistd.h>
#include<fcntl.h>

int main()
{
	int f1 = open("file1", O_RDONLY);  //open source file
	int f2 = open("file2", O_WRONLY | O_CREAT, 0644);  //create destination file
    
        char buf[100];
       int n;

       while((n = read(f1, buf, sizeof(buf))) > 0) //read from file1
       {
	       write(f2, buf, n);  //write into file2
             
       }

      close(f1);
      close(f2);
}


//OUTPUT
//(File copied)
