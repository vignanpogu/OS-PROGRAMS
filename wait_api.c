 #include <unistd.h>
#include<stdio.h>
 #include <sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t child_id,wait_fd;
	int status;
	printf("Before fork\n");
	child_id=fork();
	if(0==child_id){
	printf("in child: PID: %d   PPID: %d  \n",getpid(),getppid());
	printf("waiting to complete child\n");
	sleep(30);
	printf("child completed\n");
	}
	else{
	printf("in parent:\n");
	printf("in parent: PID: %d   PPID: %d  \n",getpid(),getppid());
	//sleep(10);
	}
	wait_fd=wait(&status);
	if(-1==wait_fd)
	{
		perror("error:");
		exit(EXIT_FAILURE);
	}
	printf("child status: %d",status);

return 0;
}

