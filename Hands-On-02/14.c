/*
============================================================================
Name : 14.c
Author : Ajay Gidd
Description : Write a simple program to create a pipe, write to the pipe, 
	read from pipe and display on the monitor.
Date: 17th Oct, 2023.
============================================================================
*/
#include <unistd.h> 
#include <stdio.h>  

void main()
{

    int pipefd[2];                
    char *writeBuffer = "Hello World !!"; 
    char *readBuffer;
    int status;         
    int readCount, writeCount; 


    status = pipe(pipefd);

    if (status == -1)
        perror("Error while creating the pipe! ");
    else
    {

        writeCount = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
        if (writeCount == -1)
            perror("Error while writing to pipe!");
        else
        {

            readCount = read(pipefd[0], &readBuffer, writeCount);
            if (readCount == -1)
                perror("Error while reading from pipe!");
            else
                printf("Data from pipe: %s\n", readBuffer);
        }
    }
}
