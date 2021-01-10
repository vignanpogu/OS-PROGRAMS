#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int event=0;
pthread_mutex_t event_mutex;
pthread_cond_t event_cond_var;
void* wait_for_event(void *data)
{
int mut_lk_err,mut_ulk_err;
printf("Wait_E: before lock\n");
mut_lk_err = pthread_mutex_lock(&event_mutex);
	if(0!=mut_lk_err){
		perror("error: wait mut_lock\n");
		exit(EXIT_FAILURE);
	}
printf("Wait_E: Grabbed Mutex\n");
printf("Wait_E: Inside_critical_region\n");
printf("Wait_E: waiting for event to 1\n");
while(event!=1){
	printf("Wait_E: before cond_var_wait\n");
	pthread_cond_wait(&event_cond_var,&event_mutex);
	printf("Wait_E: after cond_var_wait\n");
	}
printf("Wait_E: event = 1\n");
mut_ulk_err = pthread_mutex_unlock(&event_mutex);
	if(0!=mut_ulk_err){
		perror("error: wait mut_unlock\n");
		exit(EXIT_FAILURE);
	}
printf("Wait_E: mutex unlock\n");
}

void* event_setter(void *data)
{
int mut_lk_err,mut_ulk_err;
printf("E_setter: before lock\n");
sleep(2);
mut_lk_err = pthread_mutex_lock(&event_mutex);
	if(0!=mut_lk_err){
		perror("error: eve mut_lock\n");
		exit(EXIT_FAILURE);
	}
printf("E_setter: Grabbed Mutex\n");
printf("E_setter: Inside_critical_region\n");
event=1;
printf("E_setter: event = 1\n");
mut_ulk_err = pthread_mutex_unlock(&event_mutex);
	if(0!=mut_ulk_err){
		perror("error: eve mut_lock\n");
		exit(EXIT_FAILURE);
	}
printf("E_setter: Mutex unlock\n");
pthread_cond_signal(&event_cond_var);
printf("E_setter: signaling to cond_wait\n");

}

int main()
{
pthread_t wait_fr_eve_id,eve_set_id;
int wait_th_err,eve_th_err, wait_thj_err,eve_thj_err;
//creating mutex
pthread_mutex_init(&event_mutex,NULL);
//threads creation
wait_th_err = pthread_create(&wait_fr_eve_id,NULL,wait_for_event,NULL);
	if(0!=wait_th_err){
		perror("error: wait th_create\n");
		exit(EXIT_FAILURE);
	}
eve_th_err = pthread_create(&eve_set_id,NULL,event_setter,NULL);
	if(0!=eve_th_err){
		perror("error: event th_create\n");
		exit(EXIT_FAILURE);
	}
//waitibg for threads to join
wait_thj_err = pthread_join(wait_fr_eve_id,NULL);
	if(0!=wait_thj_err){
		perror("error: wait th_joinig\n");
		exit(EXIT_FAILURE);
	}
eve_thj_err = pthread_join(eve_set_id,NULL);
	if(0!=eve_thj_err){
		perror("error: eve th_joinig\n");
		exit(EXIT_FAILURE);
	}

//destroying mutex
pthread_mutex_destroy(&event_mutex);

return 0;
}
