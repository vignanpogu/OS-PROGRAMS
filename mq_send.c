#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
      
#define BUFF_SIZE 64
char buff[BUFF_SIZE];
struct mq_attr desd_mq_attr;

int main()
{

	mqd_t desd_mq_desc;
	 int mq_sd_er,mq_close_er,mq_rsv_er;       //for mq_send error check
	//attributes to msg q like no.of.msgs, max.size.of.msg , flags, etc.
	desd_mq_attr.mq_flags=0;
	desd_mq_attr.mq_maxmsg=4;
	desd_mq_attr.mq_msgsize=64;
	desd_mq_attr.mq_curmsgs=0;

	//open or create msg qs
	desd_mq_desc = mq_open("/desd_mq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR,&desd_mq_attr);
		if(-1 == desd_mq_desc){
		perror("error: mq_open \n");
		exit(EXIT_FAILURE);
		}
	
	//send msg 
	mq_sd_er =  mq_send(desd_mq_desc, "HelloChamp sender1\n",19, 0);
		if(-1 == mq_sd_er){
		perror("error: mq_send \n");
		exit(EXIT_FAILURE);
		}
	//receive msg
	/*mq_rsv_er =  mq_receive(desd_mq_desc, buff,64, 0);
		if(-1 == mq_rsv_er){
		perror("error: mq_send \n");
		exit(EXIT_FAILURE);
		}*/
	//print received msg
	printf("received msg: %s\n",buff);
	//close msg q
	mq_close_er = mq_close(desd_mq_desc);
		if(-1 == mq_close_er){
		perror("error: mq_close \n");
		exit(EXIT_FAILURE);
		}

return 0;
}
