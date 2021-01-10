#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int a,b;
sem_t sem_in_proc,sem_proc_in;

void* input_thread(void* data)
{
	while(1)
	{
	sem_wait(&sem_proc_in);
	scanf("%d",&a);
	scanf("%d",&b);
	printf("in: a = %d , b = %d\n",a,b);
	sem_post(&sem_in_proc);
	}
}

void* proc_thread(void* data)
{
	while(1)
	{
	int sum;
	sem_wait(&sem_in_proc);
	sum=a+b;
	printf("sum = %d \n",sum);
	sem_post(&sem_proc_in);
	}
}

int main()
{
	pthread_t in_id,proc_id;
	int in_j,proc_j,in_c,proc_c;
	
	int sem_in_id,sem_proc_id;
	int sem_din,sem_dproc;
	sem_in_id = sem_init(&sem_in_proc,0,0);   //sem init in to proc    sem_int=0
		if(-1==sem_in_id)
		{
		perror("error:sem_in init");
		exit(EXIT_FAILURE);
		}
	sem_proc_id = sem_init(&sem_proc_in,0,1);		//sem init proc to in    sem_int=1
		if(-1==sem_proc_id)
		{
		perror("error: sem_proc init");
		exit(EXIT_FAILURE);
		}
	in_c=pthread_create(&in_id,NULL,input_thread,NULL);  //thread in
		if(-1==in_c)
		{
		perror("error:thread create in");
		exit(EXIT_FAILURE);
		}

	proc_c=pthread_create(&proc_id,NULL,proc_thread,NULL);	//thread proc
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
		
	sem_din=sem_destroy(&sem_in_proc);			//sem destroy in_proc
		if(-1==sem_din)
		{
		perror("error: sem_in destroy");
		exit(EXIT_FAILURE);
		}
	sem_dproc=sem_destroy(&sem_proc_in);			//sem destroy proc_in
		if(-1==sem_dproc)
		{
		perror("error: sem_proc destroy");
		exit(EXIT_FAILURE);
		}

return 0;
}
