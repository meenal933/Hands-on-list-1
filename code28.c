/*
 QUE_28
 Author: Meenal Hirwani
 Description: Write a program to get maximum and minimum real time priority.

Date: August 26, 2025
========================================================================================================================================================================================
 
 */
#include <stdio.h>
#include <sched.h>

int main()
{
	int maxPr_fifo;
	int minPr_fifo;
	int maxPr_RR;
	int minPr_RR;

	//max and min Priority for FIFO scheduling
	
	maxPr_fifo= sched_get_priority_max(SCHED_FIFO);
	minPr_fifo = sched_get_priority_min(SCHED_FIFO);

	maxPr_RR= sched_get_priority_max(SCHED_RR);
	minPr_RR = sched_get_priority_min(SCHED_RR);

	  printf("for FIFO max priority= %d, min priority =%d\n", maxPr_fifo, minPr_fifo);
	  printf("for RR max priority = %d, min Priority = %d\n", maxPr_RR, minPr_RR);

	  return 0;
}


//OUTPUT
//for FIFO max priority= 99, min priority =1
//for RR max priority = 99, min Priority = 1

