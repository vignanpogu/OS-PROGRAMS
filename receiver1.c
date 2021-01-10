#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h> 
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
int *countr=NULL;

int main()
{

	pid_t fd_shm_open,fd_unl;
	int ftrunc;
	sem_t *sem_id;
	sem_id = sem_open("/desd_sem", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR , 1);
	//sem_init(sem_id,1,1);

	fd_shm_open = shm_open("/desdshm", O_CREAT| O_RDWR, S_IRUSR| S_IWUSR);
		if(-1 == fd_shm_open){
		perror("error: shm_open\n");
		exit(EXIT_FAILURE);
		}
		
	ftrunc = ftruncate(fd_shm_open,sizeof(int));
		if(-1 == ftrunc){
		perror("error: ftruncate\n");
		exit(EXIT_FAILURE);
		}
	countr= (int *) mmap(NULL,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED,fd_shm_open,0);

	while(1)
	{
		//sem_wait(sem_id);
		printf("received count = %d\n",*countr);
		sem_post(sem_id);
	}


	fd_unl= shm_unlink("/desdshm");
		if(-1 == fd_unl){
		perror("error: shm_unlink\n");
		exit(EXIT_FAILURE);
		}
	sem_close(sem_id);
return 0;
}
