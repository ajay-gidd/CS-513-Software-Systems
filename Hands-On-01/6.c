/*
============================================================================
Name : 6.c
Author : Ajay Gidd
Description :  Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 09th Sep, 2023.
============================================================================
*/
#include<unistd.h>
int main()
{
	char *buffer[100];
    	int readByteCount, writeByteCount;
	readByteCount = read(STDIN_FILENO, buffer, 1);
        writeByteCount = write(STDOUT_FILENO, buffer, 1);

        if (readByteCount == -1 || writeByteCount == -1)
        {
            perror("Error while reading from STDIN / writing to STDOUT");
           
        }
	return 0;
}
