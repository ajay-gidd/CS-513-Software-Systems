/*
============================================================================
Name : 17a.c
Author : Ajay Gidd
Description :  Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
        int fd = open("reservation.txt",O_CREAT |  O_RDWR);
	int data;
	printf("Enter the ticket number : ");
	scanf("%d",&data);
	write(fd,&data,sizeof(data));
	return 0;
}
