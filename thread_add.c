 #include <pthread.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	int b;
	}data;
int* add_func(struct *data)
{
	int a1,b1,sum;
	a1=data[0].a;
	b1=data[0].b;
	return a1+b1;
}
int main()
{
	pthread_t add_thread;
	int tfd,tjfd;
	int sum;
	data.a=10;
	data.b=20;
       tfd= pthread_create(&add_thread, NULL,add_func, &data);
	if(tfd!=0){
	perror("error: thread creation\n");
	}

	tjfd= pthread_join(add_thread, &sum);
	if(tjfd!=0){
	perror("error: at thread joining\n");
	}
	printf("sum: %d\n",sum);

return 0;
}

