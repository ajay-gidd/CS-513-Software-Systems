/*
============================================================================
Name : 23.c
Author : Ajay Gidd
Description :  Write a program to create a Zombie state of the running program.
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
		printf("Child creation failed\n");
	}
	else if(pid == 0)
	{
		printf("Child about to exit\n");
		exit(0);
	}
	else
	{
		printf("parent is running\n");
		sleep(10);
		printf("parent exit\n");
	}
	return 0;
}


