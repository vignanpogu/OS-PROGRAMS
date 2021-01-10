#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#define BUFF_SIZE 1024

int add(int a, int b){
return a+b;
}
int main()
{
unsigned char buff[BUFF_SIZE]={33,22};
unsigned char buff1[BUFF_SIZE];
pid_t id;
int pfd[2];
int pfd1[2];
int p_err,p_err1,r_err,w_err;

p_err=pipe(pfd);
	if(-1 == p_err){
	perror("Error : pipe creation\n");
	exit(EXIT_FAILURE);
	}
p_err1=pipe(pfd1);
	if(-1 == p_err1){
	perror("Error : pipe creation\n");
	exit(EXIT_FAILURE);
	}

id=fork();
	
	if(0 == id){//child
	//read from parent
	close(pfd[1]);
	r_err=read(pfd[0],buff,BUFF_SIZE);
		if(-1 == r_err){
		("Error child : reading from \n");
		exit(EXIT_FAILURE);
		}
	//printf("child read: %s",buff);
	printf("child received num1: %d\n",buff[0]);
	printf("child received num2: %d\n",buff[1]);
	//write 
	close(pfd1[0]);
	buff1[0]=add(buff[0],buff[1]);  //add functionality
	w_err=write(pfd1[1],buff1,BUFF_SIZE);
		if(-1 == w_err){
		("Error child : writing to\n");
		exit(EXIT_FAILURE);
		}
	
	printf("child return sum: %d\n",buff1[0]);
	}
	else{//parent
	//write
	close(pfd[0]);
	w_err=write(pfd[1],buff,BUFF_SIZE);
		if(-1 == w_err){
		("Error writing : to child\n");
		exit(EXIT_FAILURE);
		}
	printf("parent sending num1: %d\n",buff[0]);
	printf("parent sending num2: %d\n",buff[1]);
	//read form child
	close(pfd1[1]);
	r_err=read(pfd1[0],buff1,BUFF_SIZE);
		if(-1 == r_err){
		("error read : from child\n");
		exit(EXIT_FAILURE);
		}
	printf("parent recived sum: %d\n",buff1[0]);
	//printf("child write: %d",buff1[1]);
	}


return 0;
}


