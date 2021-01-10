 #include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
void * thread_routine(void *data){

printf("Hurrey!!!!!!!!!! im in thread\n");
}

int main()
{
 pid_t id;
int pfd,pjfd;
pthread_t test_thread;
/*id=fork();
	if(0==id){

	}
	else{
	}*/
       pfd=pthread_create(&test_thread, NULL,thread_routine, NULL);
	if(0!=pfd){
	perror("error: at thread creation\n");
	}
	printf("rajeev\n");
	pjfd= pthread_join(test_thread, NULL);
	if(0!=pjfd){
	perror("error: at thread joining\n");
	}
	printf("thread joind successfully\n");
}

