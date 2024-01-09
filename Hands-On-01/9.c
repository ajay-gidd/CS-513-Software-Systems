/*
============================================================================
Name : 9.c
Author : Ajay Gidd
Description :  Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>

int main(int arg, char** argv)
{
	struct stat s;
	int info = stat(argv[1],&s);
	//printf("%d",info);
	if(info == 0){
		printf("Inode number is:%ld\n ", s.st_ino);
	     	printf("Number of hard links:%ld\n ", s.st_nlink);
		printf("User id is:%d\n ", s.st_uid);
		printf("group user id :%d\n ", s.st_gid);
		printf("size of file :%ld\n ", s.st_size);
		printf("block size:%ld\n ", s.st_blksize);
		printf("number of blocks:%ld\n ", s.st_blocks);
		printf("time of last access: %ld\n ", s.st_atim.tv_sec);
		printf("time of last modification:%ld\n ", s.st_mtim.tv_sec);
		printf("time of last change:%ld\n ", s.st_ctim.tv_sec);	
	}else{
		printf("invalid: ");
	}
	return 0;
}
