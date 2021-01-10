 #include <unistd.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#define BUFF_SIZE 1024
int main()
{
unsigned char buff[BUFF_SIZE];
pid_t id;
int pfd[2];
int p_err,r_err,w_err;

p_err=pipe(pfd);
	if(-1 == p_err){
	perror("Error : pipe creation\n");
	exit(EXIT_FAILURE);
	}

id=fork();
	
	if(0 == id){//child
	close(pfd[1]);
	r_err=read(pfd[0],buff,BUFF_SIZE);
		if(-1 == r_err){
		("Error child : pipe read\n");
		exit(EXIT_FAILURE);
		}
	printf("child read: %s",buff);
	}
	else{//parent
	close(pfd[0]);
	w_err=write(pfd[1],"HI RAJEEV JORDAN\n",BUFF_SIZE);
		if(-1 == w_err){
		("Error child : pipe read\n");
		exit(EXIT_FAILURE);
		}
	
	}


return 0;
}


