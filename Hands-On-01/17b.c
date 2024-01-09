/*
============================================================================
Name : 17b.c
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
	int data1;
	
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_whence = SEEK_SET;
//	lock.l_pid = get_pid();
	fcntl(fd,F_SETLKW,&lock);
	read(fd,&data1,2);
	printf("Current tickect NUmber is : %d",data1);
	//fcntl(fd,F_SETLKW,&lock);
	getchar();
	data1 += 1;
	lseek(fd,0,SEEK_SET);
	write(fd,&data1,sizeof(data1));
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	int data2;
	lseek(fd,0,SEEK_SET);
       	read(fd,&data2,2);
	printf("tickect number is : %d",data2);



	
	
	return 0;
}
