/*
============================================================================
Name : 15.c
Author : Ajay Gidd
Description : Write a simple program to send some data from parent to 
    the child process.
Date: 17th Oct, 2023.
============================================================================
*/
#include <unistd.h>    
#include <sys/types.h>
#include <stdio.h>   

void main()
{
    int Pid;

    int pipefd[2];             
    int status;            
    int readCount, writeCount; 

    char *writeBuffer = "Hello child, From Parent", *readBuffer;

    status = pipe(pipefd);

    if (status == -1)
        perror("Error while creating pipe!");
    else
    {

        Pid = fork();
        if (Pid == -1)
            perror("Error whiling creating child!");
        else if (Pid == 0)
        {

            readCount = read(pipefd[0], &readBuffer, sizeof(writeBuffer));
            if (readCount == -1)
                perror("Error while reading from pipe!\n");
            else
                printf("Data from parent: %s\n", readBuffer);
        }
        else
        {

            writeCount = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeCount == -1)
                perror("Error while writing to pipe!");
        }
    }
}
