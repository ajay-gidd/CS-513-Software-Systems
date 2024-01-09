/*
============================================================================
Name : 24.c
Author : Ajay Gidd
Description :  Write a program to create an orphan process.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid = fork();

	if(pid<0)
	{
		printf("Child Creation Failed");
	}
	else if(pid == 0)
	{
		printf("Child is executing pid : %d\n",getppid());
		sleep(3);
		printf("Child is terminated pid : %d\n",getppid());
		printf("Now child process became the orphon\n");
		exit(0);
	}
	else
	{
		printf("Parent is terminating pid : %d\n",getpid());
		sleep(1);
		exit(0);
	}
	return 0;
}
