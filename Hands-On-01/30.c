/*
============================================================================
Name : 30.c
Author : Ajay Gidd
Description :  Write a program to run a script at a specific time using a Daemon process.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int pid = fork();

	if(pid == 0)
	{
		printf("%d",getpid());
		while(1)
		{

			time_t curr = time(NULL);
			struct tm *tm_struct = localtime(&curr);
			int h = tm_struct->tm_hour;
			int m = tm_struct->tm_min;

			int inputTime = atoi(argv[1]);
			int inputMinute = atoi(argv[2]);
			if(inputTime == h && inputMinute == m)
			{
				 setsid();
            			 chdir("/");
           			 umask(0);
				printf("Hello ! I,m Daemon!!");
				break;
			}
		}

	}
	else
	{
		exit(0);
	}
	return 0;
}
