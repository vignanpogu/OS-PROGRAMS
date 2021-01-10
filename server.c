#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#define BUFF_SIZE 1024
char buff[BUFF_SIZE];
struct sockaddr_in saddr;
struct sockaddr_in caddr;
int main()
{
    int ss;
    int cs;
    pid_t id;
    ss = socket(AF_INET, SOCK_STREAM, 0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.1.127");
    saddr.sin_port = htons(5678);
    bind(ss, ( struct sockaddr *)&saddr, sizeof(saddr));
    listen(ss,10);
    while(1)
    {
    socklen_t csize;
    cs = accept(ss, (struct sockaddr *)&caddr,&csize);
    id=fork();
    if(0==id)
    {
    read(cs,buff,1024);
    printf("client sent: %s \n",buff);
    write(cs,"msg from server\n",16);
    close(cs);
    }
    else
    {
        
    }
    }
    close(ss);
    
return 0;
}