/*
============================================================================
Name : 20a.c
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
    int Status;                              
    char data[] = "Sending data from program 20a!"; 
    int fd;                          
    char *fifoFile = "./20-fifo";                
    int writeCount;                             

   Status = mkfifo(fifoFile, S_IRWXU);

    if (Status == -1)
        perror("Error while creating FIFO file!");
    fd = open(fifoFile, O_WRONLY);
    if (fd == -1)
        perror("Error while opening FIFO file for writing");
    else
    {
        writeCount = write(fd, &data, sizeof(data));
        if (writeCount == -1)
            perror("Error while writing to the file!");
        close(fd);
    }
}
