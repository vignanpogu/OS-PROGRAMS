#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int a,b;
sem_t sem_in_proc;

void* input_thread(void* data)
{
	while(1)
	{
	scanf("%d",&a);
	scanf("%d",&b);
	printf("input thread: a = %d , b = %d\n",a,b);
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
	printf("proc thread: sum = %d \n",sum);
	}
}

int main()
{
	pthread_t in_id,proc_id;
	int in_c,proc_c, in_j,proc_j;
	

	sem_init(&sem_in_proc,0,0);
	in_c=pthread_create(&in_id,NULL,input_thread,NULL);
		if(-1==in_c)
		{
		perror("error:");
		exit(EXIT_FAILURE);
		}

	proc_c=pthread_create(&proc_id,NULL,proc_thread,NULL);
		if(-1==proc_c)
		{
		perror("error:");
		exit(EXIT_FAILURE);
		}
	in_j=pthread_join(&in_id,NULL);
		if(-1==in_j)
		{
		perror("error:");
		exit(EXIT_FAILURE);
		}
	proc_j=pthread_join(&proc_id,NULL);
		if(-1==proc_j)
		{
		perror("error:");
		exit(EXIT_FAILURE);
		}
	
	sem_destroy(&sem_in_proc);

return 0;
}
