/*
 QUE_29
 Author: Meenal Hirwani
 Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).

Date: August 26, 2025
=======================================================================================================================================================================================
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int policy){
	switch(policy){
		case SCHED_OTHER:
		printf("This is SCHED_OTHER scheduling policy\n");
		break; 
		case SCHED_FIFO:
		printf("This is FIFO scheduling policy\n");
		break;
		case SCHED_RR:
		printf("This is RR scheduling policy\n");
		break;
                default:
		printf("Unknown scheduling policy\n");
		break;
	}
}


int main(int argc, char*argv[])
{
	struct sched_param param;
	int policy;
	pid_t pid = getpid(); //get the current process id

	//get the current scheduling policy
	policy = sched_getscheduler(pid);
	if(policy == -1)
	{
		perror("sched_getscheduler failed");
		return EXIT_FAILURE;
	}

	//printthe current schedulig policy 
	print_policy(policy);

	//set the new scheduling policy
	if(argc !=2)
	{
		printf("usage: %s", argv[0]);
		return EXIT_FAILURE;
	}

	if(strcmp(argv[1],"SCHED_FIFO") == 0)
	{
		policy = SCHED_FIFO;
	}
	else if(strcmp(argv[1], "SCHED_RR") == 0)
	{ 
		policy = SCHED_RR;
	}
	else 
	{
		printf("Invalid Scheduling policy\n");
		return EXIT_FAILURE;
	}


	//set the scheduling priority
	param.sched_priority =15;

	//changing the scheduling policy
	if(sched_setscheduler(pid, policy, &param) == -1)
	{
		perror("sched_setscheduler failed");
		return EXIT_FAILURE;
	}

	//confirm the change
	policy = sched_getscheduler(pid);
	if(policy == -1)
	{
		perror("sched_getscheduler failed");
		return EXIT_FAILURE;
	}

	printf("scheduling policy successfully change\n");
	print_policy(policy);
	return 0;
}




		
//OUTPUT
//This is SCHED_OTHER scheduling policy

