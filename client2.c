#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#include <sys/types.h>          /* See NOTES */
#define BUFF_SIZE 1024
char buff[BUFF_SIZE];
struct sockaddr_in saddr;
struct sockaddr_in caddr;
int main()
{
    int ss;
    int cs;
    cs = socket(AF_INET, SOCK_STREAM, 0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.1.127");
    saddr.sin_port = htons(5678);
    bind(ss, &saddr, sizeof(saddr));
   // listen(ss,10);
    socklen_t csize;
    ss = connect(cs, (struct sockaddr *)&saddr,sizeof(saddr));
      write(cs,"hi rajeev client2\n",18);
    read(cs,buff,1024);
    printf("reciver sent: %s \n",buff);
  
    close(ss);
    close(cs);
return 0;
}