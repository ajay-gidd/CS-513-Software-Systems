/*
============================================================================
Name : 25.c
Author : Ajay Gidd
Description :  Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<time.h>
#include<sys/resource.h>
int main()
{
	int child1,child2,child3;

	child1 = fork();

	if(child1 == -1)
	{
		printf("Child1 creation failed");
		exit(0);
	}
	else if(child1 == 0)
	{
		printf("1 : %d\n",getpid());
		sleep(5);
		exit(0);
	}

	child2 = fork();

	if(child2 == -1)
	{
		printf("Child2 creation failed");
		exit(0);
	}
	else if(child2 == 0)
	{
		printf("2 : %d\n",getpid());
		sleep(10);
		exit(0);
	}

	child3 = fork();

	if(child3 == -1)
	{
		printf("Child3 creation failed");
		
		exit(0);
	}
	else if( child3 == 0)
	{
		printf("3 : %d\n",getpid());
		sleep(15);
		exit(0);
	}

	int p;

	printf("Enter the proccess id  to wait\n");
	scanf("%d",&p);

	int status;
        int  ter = waitpid(p, &status,0);
	printf("%d is waiting\n",p);

	if(ter == -1)
	{
		printf("childing waiting failed");
	}

	if(WIFEXITED(status))
	{
		printf("process %d is exited\n",p);
	}

	printf("parent continues execution");
	return 0;
}
