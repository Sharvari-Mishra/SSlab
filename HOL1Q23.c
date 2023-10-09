/*
============================================================================
Name : Q23.c
Author : Sharvari Mishra
Description : Write a program to create a Zombie state of the running program.
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(){
	pid_t p;
	p=fork();
	if(p==0){
		printf("Child having id %d\n",getpid());
		exit(0);
	}
	else{
		printf("Parent having id %d\n",getpid());
		sleep(20);
	}
}
