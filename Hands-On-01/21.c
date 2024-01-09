/*
============================================================================
Name : 21.c
Author : Ajay Gidd
Description :  Write a program, call fork and print the parent and child process id.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	if(fork())
	{
		printf("Parent processid : %d\n", getpid());
	}
	else
	{
		printf("Child processid : %d",getpid());
	}
	return 0;
}
