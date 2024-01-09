/*
============================================================================
Name : 16.c
Author : Ajay Gidd
Description : Write a program to send and receive data from parent to child 
    vice versa. Use two way communication.
Date: 17th Oct, 2023.
============================================================================
*/
#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>     

void main()
{

    int childToParentfd[2], parentToChildfd[2]; 
    int childStatus;
    int parentStatus; 
    int readCount, writeCount;   
    char *writeBuffer, *readBuffer;

    int childPid;

    childStatus = pipe(childToParentfd);
    parentStatus = pipe(parentToChildfd);

    if (childStatus == -1 || parentStatus == -1)
        perror("Error while creating the pipe!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while creating child!");
        else if (childPid == 0)
        {

            close(parentToChildfd[1]); 
            close(childToParentfd[0]);


            writeBuffer = "Hi parent! from child!";
            writeCount = write(childToParentfd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeCount == -1)
                perror("Error while writing,child to parent pipe!");


            readCount = read(parentToChildfd[0], &readBuffer, 8);
            if (readCount == -1)
                perror("Error while reading from parent to child pipe!");
            else
                printf("parent : %s\n", readBuffer);
        }
        else
        {
            close(parentToChildfd[0]); 
            close(childToParentfd[1]); 


            writeBuffer = "Hi child! from parent!";
            writeCount = write(parentToChildfd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeCount == -1)
                perror("Error while writing to  parent to child pipe!");



            readCount = read(childToParentfd[0], &readBuffer, 8);
            if (readCount == -1)
                perror("Error while reading from child to parent pipe!");
            else
                printf("child : %s\n", readBuffer);
        }
    }
}
