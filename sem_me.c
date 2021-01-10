#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int count=0;
sem_t sem_count;

void* increment_thread(void* data)
{
	while(1)
	{
	sem_wait(&sem_count);
	count++;
	printf("increment:  %d \n",count);
	sem_post(&sem_count);
	}
}

void* decrement_thread(void* data)
{
	while(1)
	{
	sem_wait(&sem_count);
	count--;
	printf("decrement: %d \n",count);
	sem_post(&sem_count);
	}
}

int main()
{
	pthread_t in_id,proc_id;
	int in_j,proc_j,in_c,proc_c;
	
	int sem_in_id;
	int sem_din;
	sem_in_id = sem_init(&sem_count,0,1);   //sem init in to proc    sem_int=1 mutual exclusion
		if(-1==sem_in_id)
		{
		perror("error:sem_count init");
		exit(EXIT_FAILURE);
		}
	
	in_c=pthread_create(&in_id,NULL,increment_thread,NULL);  //thread in
		if(-1==in_c)
		{
		perror("error:thread create in");
		exit(EXIT_FAILURE);
		}

	proc_c=pthread_create(&proc_id,NULL,decrement_thread,NULL);	//thread proc
		if(-1==proc_c)
		{
		perror("error: thread create proc");
		exit(EXIT_FAILURE);
		}
	in_j=pthread_join(in_id,NULL);					// join thread in
		if(-1==in_j)
		{
		perror("error: thread join in");
		exit(EXIT_FAILURE);
		}
	proc_j=pthread_join(proc_id,NULL);				//join thread proc
		if(-1==proc_j)
		{
		perror("error: thread join proc");
		exit(EXIT_FAILURE);
		}
		
	sem_din=sem_destroy(&sem_count);			//sem destroy in_proc
		if(-1==sem_din)
		{
		perror("error: sem_in destroy");
		exit(EXIT_FAILURE);
		}
	

return 0;
}
