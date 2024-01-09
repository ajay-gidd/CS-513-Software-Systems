/*
============================================================================
Name : 15.c
Author : Ajay Gidd
Description :  Write a program to display the environmental variable of the user (use environ).
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
//using namespace std;
int main(int arg, char* argv[], char* env[])
{
	int i;
	for(i = 0;env[i] != NULL;i++)
	{
		printf("\n%s",env[i]);
	
	}
	return 0;
}
