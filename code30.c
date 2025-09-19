/*
 QUE_30
 Author: Meenal Hirwani
 Description: Write a program to run a script at a specific time using a daemon process.

Date: August 26, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	pid_t pid = fork();

    	if(pid > 0){
        	exit(0);
    	}

    	// Child becomes daemon
    	if(setsid() < 0){
		exit(1);
	}
    	umask(0);
    	chdir("/");

	close(STDIN_FILENO);
    	close(STDOUT_FILENO);
    	close(STDERR_FILENO);

    	// Targeted time
    	int target_hour = 23;
    	int target_min = 30;

    	while(1){
        	time_t now = time(NULL);
        	struct tm *lt = localtime(&now);

       	 	if (lt->tm_hour == target_hour && lt->tm_min == target_min) {
            		system("home/hp/myscript.sh");
            		sleep(60);
        	}
        	sleep(30);
    	}

    return 0;
}

/*
cat /home/hp/myscript.log
Hello, Script executed at Fri Sep 19 11:30:18 PM IST 2025
*/
