#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

int main()
{
	unsigned char buff[BUFF_SIZE]={5,6};
	unsigned char buff1[BUFF_SIZE];
	int f_err,r_err,w_err,o_err,c_err;
	int sender_fd,receiver_fd;
     
	sender_fd=open("sumfifo",O_WRONLY);
	if(-1==sender_fd){
		perror("error: fifo creation\n");
		exit(EXIT_FAILURE);
		}
	receiver_fd=open("returnfifo",O_RDONLY);
	if(-1==receiver_fd){
		perror("error: reciver fifo creation\n");
		exit(EXIT_FAILURE);
		}
	w_err=write(sender_fd,buff,BUFF_SIZE);
	if(-1==w_err){
		perror("error: write\n");
		exit(EXIT_FAILURE);
		}
	
	printf("sending num1: %d\n",buff[0]);
	printf("sending num2: %d\n",buff[1]);
	read(receiver_fd,buff1,BUFF_SIZE);
	if(-1==r_err){
		perror("error: read\n");
		exit(EXIT_FAILURE);
		}
	
	printf("recived sum: %d\n",buff1[0]);
	close(sender_fd);
	close(receiver_fd);

return 0; 
}

