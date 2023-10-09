#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>



int main(int argc, char* argv[]){

	struct sched_param s;
	int pid = getpid();//atoi(argv[1]);
	printf("PID: %d\n",pid);

	sched_getparam(pid,&s);
	printf("Current Priority: %d\n",s.sched_priority);

	nice(5);
	// int t = 5;
	// wait(&t);

	sched_getparam(pid,&s);
	printf("Updated Priority: %d\n",s.sched_priority);

}
