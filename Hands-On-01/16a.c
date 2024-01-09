/*
============================================================================
Name : 16a.c
Author : Ajay Gidd
Description :  Write a program to perform mandatory locking.
a. Implement write lock
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	struct flock lock;
	int fd;

	fd = open("test1.txt",O_RDWR);
	lock.l_type = F_RDLCK;
	lock.l_start=0;
	lock.l_len = 0;
	lock.l_whence = SEEK_SET;
	lock.l_pid = getpid();
	printf("Before entering into critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside critical section\n");
	printf("unlocking\n");
	getchar();
	printf("unlocked\n");
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("finish");
	return 0;
}
