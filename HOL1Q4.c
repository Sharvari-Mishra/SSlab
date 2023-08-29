#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
int fd1=open("HOLDemo1.txt",O_RDWR);
int fd2=open("HOLDemo.txt",O_EXCL);
if(fd1<0){
	perror("\nFile1 Couldn't open");
	exit(1);
}
printf("\nFile1 open with descriptor %d",fd1);
if(fd2<0){
	perror("\nFile2 couldn't open.");
	exit(1);
}
printf("\nFile2 open with descriptor %d",fd2);
return 0;
}

