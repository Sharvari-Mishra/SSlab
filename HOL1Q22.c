/*
============================================================================
Name : Q22.c
Author : Sharvari Mishra
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	int fd;
	fd=open("Q22.txt",O_RDWR);
	if(fd<0){
		printf("File Could not open.");
		exit(0);
	}
	pid_t p;
	p=fork();
	char parent_buffer[10];
	char child_buffer[10];
	if(p==0){
                printf("Message from Child:");
		scanf("%[^\n]",child_buffer);
		write(fd,child_buffer,10);
		printf("Message from child added successfully.\n");
		exit(0);
        }
        else{
                printf("Message from Parent:");
		wait(NULL);
                scanf("%[^\n]",parent_buffer);
                write(fd,parent_buffer,10);
                printf("Message from parent  added successfully.\n");
		exit(0);

        }
	


}
