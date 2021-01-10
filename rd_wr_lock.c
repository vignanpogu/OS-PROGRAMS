#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count=0;
pthread_rwlock_t rw_lock_count;

void* increment(void *data)
{
while(1){
pthread_rwlock_wrlock(&rw_lock_count);
printf("write: lock\n");
count++;
printf("inc: %d\n",count);
pthread_rwlock_unlock(&rw_lock_count);
}


}

void* print(void *data)
{
while(1){
pthread_rwlock_rdlock(&rw_lock_count);
printf("read: print lock\n");
printf("print: count =%d\n",count);
pthread_rwlock_unlock(&rw_lock_count);
}
}

void* add_count(void *data)
{
while(1){
pthread_rwlock_rdlock(&rw_lock_count);
printf("read: add lock\n");
int add=count+10;
printf("add_count: %d \n",add);
pthread_rwlock_unlock(&rw_lock_count);

}
}

int main()
{
pthread_t inc_id,print_id,add_count_id;
int inc_th_err,prnt_th_err,add_th_err;    //used for error checking conditions for threads creation
int inc_thj_err,prnt_thj_err,add_thj_err;  //used for error checking conditions for threads joining
//read-write lock initialization
pthread_rwlock_init(&rw_lock_count,NULL);

//thread creations
inc_th_err = pthread_create(&inc_id,NULL,increment,NULL);
	if(0!=inc_th_err){
	perror("error: inc thread_create\n");
	exit(EXIT_FAILURE);
	}
prnt_th_err = pthread_create(&print_id,NULL,print,NULL);
	if(0!=prnt_th_err){
	perror("error: print thread_create\n");
	exit(EXIT_FAILURE);
	}
prnt_th_err = pthread_create(&add_count_id,NULL,add_count,NULL);
	if(0!=prnt_th_err){
	perror("error: add_count thread_create\n");
	exit(EXIT_FAILURE);
	}	

//waitnig for threads to join
prnt_thj_err=pthread_join(inc_id,NULL);
	if(0!=prnt_thj_err){
	perror("error: add_count thread_join\n");
	exit(EXIT_FAILURE);
	}
prnt_thj_err=pthread_join(print_id,NULL);
	if(0!=prnt_thj_err){
	perror("error: add_count thread_join\n");
	exit(EXIT_FAILURE);
	}
prnt_thj_err=pthread_join(add_count_id,NULL);
	if(0!=prnt_thj_err){
	perror("error: add_count thread_join\n");
	exit(EXIT_FAILURE);
	}

//destroying read-write lock
pthread_rwlock_destroy(&rw_lock_count);


return 0;
}
