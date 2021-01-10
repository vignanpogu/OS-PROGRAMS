 #include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define BUFF_SIZE 5
int * add_func(int *data)
{
	int b=0;
	for(int i=0; i<BUFF_SIZE; i++){
	b+=data[i];
	}
	
	return b;
}
int main()
{
	pthread_t add_thread;
	int buff[BUFF_SIZE]={10,20,30};
	int tfd,tjfd;
	int sum;
     	  tfd= pthread_create(&add_thread, NULL,add_func, buff);
	if(tfd!=0){
	perror("error: thread creation\n");
	}

	tjfd= pthread_join(add_thread, &sum);
	if(tjfd!=0){
	perror("error: at thread joining\n");
	}
	printf("Sum: %d\n",sum);
return 0;
}

