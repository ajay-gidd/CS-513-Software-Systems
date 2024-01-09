/*
============================================================================
Name : 8.c
Author : Ajay Gidd
Description :  Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 09th Sep, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc,char* argv[]){
       int file_read =  open(argv[1],O_RDONLY);

       if(file_read == -1){
         perror("File not opening");
         return 0;
       }
       char buf[1];
       while((read(file_read,buf,1)) == 1){
        if(buf[0] == '\n')
	{
		write(1,"\n\n",2);
       }
	else
	{
		write(1,buf,1);
	}

       }
       close(file_read);
       
}
