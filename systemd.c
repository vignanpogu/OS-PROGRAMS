 #include <unistd.h>
#include<stdio.h>
int main()
{
	pid_t id;
	printf("Before fork\n");
	id=fork();
	if(0==id){
	printf("in child: PID: %d   PPID: %d  \n",getpid(),getppid());
	sleep(30);
	}
	else{
	printf("in parent: PID: %d   PPID: %d  \n",getpid(),getppid());
	sleep(10);
	printf("parent died\n");
	}
	printf("after fork!\n");
return 0;
}

