/*
============================================================================
Name : 20.c
Author : Ajay Gidd
Description :  Find out the priority of your running program. Modify the priority with nice command.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/resource.h>
int main()
{
	int niceV;
	int pid = getpid();

	niceV = getpriority(PRIO_PROCESS,0);
	printf("pid : %d, nice : %d\n",pid,niceV);
	getchar();
	nice(5);
	niceV = getpriority(PRIO_PROCESS,0);
	printf("pid : %d, nice : %d\n",pid,niceV);
	while(1);
	return 0;
}

