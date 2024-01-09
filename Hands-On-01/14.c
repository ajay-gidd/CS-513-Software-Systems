/*
============================================================================
Name : 14.c
Author : Ajay Gidd
Description :  Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int arg, char** argv)
{
	struct stat s;
	//s = (struct stat*)malloc(sizeof(struct stat));

	stat(argv[1],&s);
	if(S_ISREG(s.st_mode))
	{
		printf("File Type is : Regular");
	}
	else if(S_ISDIR(s.st_mode))
	{
		printf("File Type is : Directory");
	}
	else if(S_ISCHR(s.st_mode))
	{
		printf("File Type is : Character");
	}
	else if(S_ISBLK(s.st_mode))
	{
		printf("File Type is : Block");
	}
	else
	{
		printf("File Type is : FIFO");
	}



	return 0;
}

