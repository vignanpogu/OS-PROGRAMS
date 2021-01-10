#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define SIZE 32
int main()
{
	pid_t id;
	int fd_exec;
	unsigned char cmd[SIZE];
	unsigned char cmd1[SIZE];
	unsigned char arg[SIZE];
	while(1){
	scanf("%s",cmd); //path
	scanf("%s",cmd1);//command
	scanf("%s",arg);
	id=fork();
	if(0==id){
	fd_exec=execl(cmd,cmd1,arg,NULL);
		if(-1==fd_exec){
		perror("error: exec");
		exit(EXIT_FAILURE);		
		}
	
	}
	else{
	
	}
	}

	return 0;


}
