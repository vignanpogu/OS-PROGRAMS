#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t id;
	printf("before fork\n");
	id=fork();
	if(0==id){
	printf("child: PID %d   PPID: %d \n",getpid(),getppid());
	sleep(20);
	}
	else{
	printf("parent: PID: %d PPID %d\n",getpid(),getppid());
	}

	return 0;


}
