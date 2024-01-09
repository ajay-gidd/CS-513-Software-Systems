/*
============================================================================
Name : 13.c
Author : Ajay Gidd
Description :  Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/select.h>
#include<sys/time.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	struct timeval tv;
	fd_set readfs;
	int ret;

	tv.tv_sec = 10;
	tv.tv_usec = 0;
	FD_ZERO(&readfs);
	FD_SET(0,&readfs);

	ret = select(1,&readfs,NULL,NULL,&tv);
	if(ret)
	{
		printf("data available in 10 sec");
	}
	else
	{
		printf("data is NOT within 10 sec");
	}
	return 0;

}
