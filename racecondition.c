#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int count=0;
void* inc_func(void *data){
	while(1){
		count++;
		printf("increment: %d\n",count);
		
	}
}

void* dec_func(void *data){
	while(1){
		count--;
		printf("decrement: %d\n",count);
		
	}
}

int main()
{
	pthread_t inc_thread,dec_thread;
	int inc_tfd,dec_tfd;
	dec_tfd=pthread_create(&dec_thread,NULL,dec_func,NULL);
		if(0!=inc_tfd){
		perror("error:dec thread creation\n");
		}
	inc_tfd=pthread_create(&inc_thread,NULL,inc_func,NULL);
		if(0!=inc_tfd){
		perror("error:inc thread creation\n");
		}
	
	pthread_join(dec_thread,NULL);
	pthread_join(inc_thread,NULL);
return 0;
}
