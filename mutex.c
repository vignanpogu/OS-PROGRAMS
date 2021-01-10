#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int count=0;
pthread_mutex_t  count_mutex;
void* inc_func(void *data){
	while(1){
		pthread_mutex_lock(&count_mutex);
		count++;
		printf("increment: %d\n",count);
		pthread_mutex_unlock (&count_mutex);
		
	}
}

void* dec_func(void *data){
	while(1){
		pthread_mutex_lock(&count_mutex);
		count--;
		printf("decrement: %d\n",count);
		pthread_mutex_unlock (&count_mutex);
	}
}

int main()
{
	pthread_t inc_thread,dec_thread;
	int inc_tfd,dec_tfd,mifd,mdfd;
	mifd=pthread_mutex_init (&count_mutex,NULL); 
	if(0!=mifd){
		perror("error:mutex creation\n");
		}
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
	mdfd=pthread_mutex_destroy (&count_mutex);
	if(0!=mdfd){
		perror("error:mutex creation\n");
		}
	
return 0;
}
