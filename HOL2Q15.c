/*
 * ============================================================================
 Name : 15.c
 Author : Sharvari Mishra
 Description : Write a simple program to send some data from parent to the child process.
 Date: 7th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int fd[2];
	int childID=0;
	pipe(fd);


	if(fork()!=0){
		close(fd[0]);
		childID=1;
		write(fd[1], &childID,sizeof(childID));
		printf("Parent (%d) send ChildId: %d\n",getpid(),childID);

		close(fd[1]);
	}
	else{
		close(fd[1]);
		read(fd[0], &childID, sizeof(childID));
		printf("Child(%d) received child ID:%d\n", getpid(),childID);
		close(fd[0]);
	}


}
