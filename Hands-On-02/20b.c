/*
============================================================================
Name : 20b.c
Author : Ajay Gidd
Description : Write two programs so that both can communicate by FIFO -Use 
    one way communication.
Date: 17th Oct, 2023.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    int fd;           
    char *fifoFile = "./20-fifo"; 
    int readCount;                
    char data[100];               

    fd = open(fifoFile, O_RDONLY);

    if (fd == -1)
        perror("Error while opening the FIFO file!");
    else
    {
        readCount = read(fd, data, 100);
        if (readCount == -1)
            perror("Error while reading from the FIFO file!");
        else
        {

            printf("Data from the FIFO file - %s\n", data);
        }
        close(fd);
    }
}
