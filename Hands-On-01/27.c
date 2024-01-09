/*
============================================================================
Name : 27.c
Author : Ajay Gidd
Description :  Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("1 : execl\n");
	printf("2 : execlp\n");
	printf("3 : execle\n");
	printf("4 : execv\n");
	printf("5 : execvp\n");
	printf("Enter your choice from 1-5\n");
	int n;
	scanf("%d",&n);
	if(n == 1)
	{
		
		printf("Executing Command using execl\n");
		execl("/bin/ls","ls","-RL",NULL);
		printf("----------------------------------------------------------------------------------------------\n");
	}
	else if(n == 2)
	{


		printf("Executing Command using execlp\n");
        	execlp("ls","ls","-RL",NULL);
        	printf("----------------------------------------------------------------------------------------------\n");
	}
	else if(n == 3)
	{
		char *env[] = {NULL};
		printf("Executing command using execle\n");
		execle("/bin/ls","ls","-RL",NULL,env);
	}
	else if(n == 4)
        {
                char *env[] = {"ls","-RL",NULL};
                printf("Executing command using execv\n");
                execv("/bin/ls",env);
        }
	else if(n == 4)
        {
                char *env[] = {"ls","-RL","/test/tmp.txt",NULL};
                printf("Executing command using execvp\n");
                execvp("ls",env);
        }




	return 0;
}

