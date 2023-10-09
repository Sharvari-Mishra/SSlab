/*
============================================================================
Name : Q21.c
Author : Sharvari Mishra
Description : Write a program, call fork and print the parent and child process id.
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
void main(){
	pid_t p;
	printf("Pid of the Main Program:\t%d\n",getpid());
	p=fork();

	if(p==0){
		printf("In child Process,\tpid:\t%d,\tppid:\t%d\n",getpid(),getppid());
	}
	else{
		printf("In parent,\t\tpid:\t%d,\tfork returned:\t%d\n",getpid(),p);

	}
	
}
