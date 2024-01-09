/*
============================================================================
Name : 12.c
Author : Ajay Gidd
Description :  Write a program to find out the opening mode of a file. Use fcntl.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("test1.txt",O_RDONLY);
	//int fd = fileno(file);
	int mode = fcntl(fd,F_GETFL);
//	printf("%d",mode);
	switch(mode){
    		case 32768 : printf("r"); break;
    		case 32769 : printf("w"); break;
    		case 33793 : printf("a"); break;
    		case 32770 : printf("r+ || w+"); break;
   	 	case 32794 : printf("a+"); break;
}
	return 0;
}
