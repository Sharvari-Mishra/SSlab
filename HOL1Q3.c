#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int fd1=open("HOLDemo.txt",O_RDONLY|O_CREAT);
	if(fd1<0){
		perror("\nFile couldn't open.");
		exit(1);
	}
	printf("\nFile is open with fd= %d\n",fd1);

	if(close(fd1) <0){
		perror("\nFile could not be closed.");
		exit(1);
	}
	printf("\nFile Closed.");
}

