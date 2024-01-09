/*
============================================================================
Name : 22.c
Author : Ajay Gidd
Description :  Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	int fd = open("test1.txt",O_CREAT | O_RDWR);
	//printf("%d",fd);
	if(fork())
	{
		
		write(fd,"I'm parent of this process  ",27);
	}
	else
	{
		//char buff2[50];
		//buff2 = "I,m child of this process";
		write(fd,"I,m child of this process",26);

	}
	close(fd);

	return 0;
}

