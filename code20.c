/*
 QUE_20
 Author: Meenal Hirwani
 Description: Find out the priority of your running program. Modify the priority with nice command.
 
Date: August 19, 2025
========================================================================================================================================================================================

 */

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	int priority; 


	//Getting the current priority 
	int oldPriority = getpriority(PRIO_PROCESS,0);
        printf("OLD PRIORITY: %d\n", oldPriority);

        
        //set the new priority 
	
        if(setpriority(PRIO_PROCESS, 0, priority) == -1)	
	{
		//setpriority returns 0 when successful else -1
		perror("set priority error");
		return 1;
	}

	//get the updated priority
	int new_priority = nice(5);
	printf("NEW PRIORITY: %d\n", new_priority);

	sleep(100);

	return 0;
}

/*
 OUTPUT
OLD PRIORITY: 0
NEW PRIORITY: 15

 
 */

