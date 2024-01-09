/*
============================================================================
Name : 10.c
Author : Ajay Gidd
Description :  Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	

	int flptr = open("test1.txt",O_CREAT | O_WRONLY | O_RDONLY);
	//printf("%d",flptr);
	char* buf1 = "Ajay Gidd is Here!!";
	char buf2[10];



	write(flptr,buf1,10);
	int ls = lseek(flptr,10,SEEK_CUR);
        write(flptr,buf1,10);
	printf("%d",ls);
	//int flptr1 = open("test1.txt",OD);
	//read(flptr,buf2,10);
	//write(1,buf2,10);
	return 0;
}



