#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int event=0;
sem_t sem_event,sem_wait_eve;

void* wait_for_event(void *data)
{
int sem_ev_p_err,sem_w_w_err;
while(event!=1){
	printf("wait: in wait critical region\n");
	sem_ev_p_err = sem_post(&sem_event);
		if(-1 == sem_ev_p_err){
		perror("error: sem_event post\n");
		exit(EXIT_FAILURE);
		}
	printf("wait: waiting in critical for event to set\n");
	sem_w_w_err = sem_wait(&sem_wait_eve);
		if(-1 == sem_w_w_err){
		perror("error: sem_wait_eve wait\n");
		exit(EXIT_FAILURE);
		}
	}
printf("wait: waiting is over\n");
printf("Wait: event = 1\n");
printf("Hurrey success!!!\n");

}

void* event_setter(void *data)
{
int sem_eve_w_err,sem_wait_p_err;
sleep(2);
sem_eve_w_err = sem_wait(&sem_event);	
	if(-1 == sem_eve_w_err){
		perror("error: sem_event wait\n");
		exit(EXIT_FAILURE);
		}
printf("setter: inside eve critical\n");
printf("setter: setting event\n");
event=1;
printf("setter:  event = 1\n");
sem_wait_p_err = sem_post(&sem_wait_eve);
	if(-1 == sem_wait_p_err){
		perror("error: sem_wait_eve post\n");
		exit(EXIT_FAILURE);
		}
printf("setter: signaling to wait\n");

}

int main()
{
pthread_t wait_fr_eve_id,eve_set_id;
int wait_j,eve_j,wait_c,eve_c,sem_dwait,sem_deve;

//semaphores initialization
sem_init(&sem_wait_eve,0,0);
sem_init(&sem_event,0,1);
//thread creation
wait_c = pthread_create(&wait_fr_eve_id,NULL,wait_for_event,NULL);	
	if(-1==wait_c)
		{
		perror("error: thread create waiting for event\n");
		exit(EXIT_FAILURE);
		}
eve_c = pthread_create(&eve_set_id,NULL,event_setter,NULL);
	if(-1==eve_c)
		{
		perror("error: thread create event setter\n");
		exit(EXIT_FAILURE);
		}
	
//thread join
wait_j = pthread_join(wait_fr_eve_id,NULL);
	if(-1==wait_j)
		{
		perror("error: thread join waiting");
		exit(EXIT_FAILURE);
		}	
eve_j = pthread_join(eve_set_id,NULL);
	if(-1==eve_j)
		{
		perror("error: thread join eve set");
		exit(EXIT_FAILURE);
		}
	
sem_dwait = sem_destroy(&sem_wait_eve);
	if(-1==sem_dwait)
		{
		perror("error: sem_wait destroy");
		exit(EXIT_FAILURE);
		}
sem_deve = sem_destroy(&sem_event);
	if(-1==sem_deve)
		{
		perror("error: sem_eve destroy");
		exit(EXIT_FAILURE);
		}

return 0;
}
