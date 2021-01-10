#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_barrier_t smrt_brdg_barrier;

void* lcd(void *data)
{
printf("LCD: Init_start\n");
sleep(2);
printf("LCD: Init_end\n");
pthread_barrier_wait(&smrt_brdg_barrier);
printf("LCD: functionality_start\n");

}

void* serial(void *data)
{
printf("serial: Init_start\n");
sleep(7);
printf("serial: Init_end\n");
pthread_barrier_wait(&smrt_brdg_barrier);
printf("serial: functionality_start\n");

}

void* cloud(void *data)
{
printf("Cloud: Init_start\n");
sleep(5);
printf("Cloud: Init_end\n");
pthread_barrier_wait(&smrt_brdg_barrier);
printf("Cloud: functionality_start\n");

}

void* vibration(void *data)
{
printf("Vib: Init_start\n");
sleep(10);
printf("Vib: Init_end\n");
pthread_barrier_wait(&smrt_brdg_barrier);
printf("Vib: functionality_start\n");

}


int main()
{
pthread_t lcd_id,serial_id,cloud_id,vib_sen_id;

pthread_barrier_init(&smrt_brdg_barrier,NULL,4);

pthread_create(&lcd_id,NULL,lcd,NULL);
pthread_create(&serial_id,NULL,serial,NULL);
pthread_create(&cloud_id,NULL,cloud,NULL);
pthread_create(&vib_sen_id,NULL,vibration,NULL);

pthread_join(lcd_id,NULL);
pthread_join(serial_id,NULL);
pthread_join(cloud_id,NULL);
pthread_join(vib_sen_id,NULL);

pthread_barrier_destroy(&smrt_brdg_barrier);
return 0;
}
