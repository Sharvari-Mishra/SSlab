/*
============================================================================
Name : Q25.c
Author : Sharvari Mishra
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

void main(){
	pid_t p[3];
	int status;
	int i;	
	for(i=0;i<3;i++){
		p[i]=fork();
		if(p[i]==-1){
			perror("Fork Failure\n");
			exit(EXIT_FAILURE);
		}
		else if(p[i]==0){
			printf("Child %d (PID %d) is running.\n",i+1,getpid());
			sleep(2);
			printf("Child %d (PID %d) is Terminated.\n",i+1,getpid());
			exit(EXIT_SUCCESS);
		}
	}
	int waited_pid;
	waited_pid=waitpid(p[1],&status,0);
	if(waited_pid==-1){
		perror("WaitPID Error\n");
		exit(EXIT_FAILURE);
	}
	if(WIFEXITED(status)){
		printf("Parent: Child %d (PID %d) has exited with status %d\n",2,waited_pid,WEXITSTATUS(status));
	}


}
