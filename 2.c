/*

 Que_2
 Author: Meenal Hirwani
 Description: Write a simple program to execute in an infinite loop at thr background. Go to /proc directory and identify all the process related information in the corresponding proc directory.  
   
 Date: August 5, 2025 
=======================================================================================================================================================================================   
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	while(1)
	{
		printf(" ");
		sleep(5);
	}
	return 0;
}

/* 


To run the program in the background:
compile
and Run: ./<Output_file_name> &

//It will give pid using &
[1] PID

open another terminal 
give command: ls -l /proc/PID

to kill the process
kill -9 PID

*/
