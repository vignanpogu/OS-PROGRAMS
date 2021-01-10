#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
int fd,fd_destination;
char buff[20];
int size,size1;
//open source file
fd=open("source.txt",O_RDONLY);
if(fd==-1)
{
perror("error in opening source file");
exit(EXIT_FAILURE);
}

//open destination file
fd_destination=open("destination.txt",O_WRONLY|O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);
if(fd_destination==-1)
{
perror("error in opening destination file");
exit(EXIT_FAILURE);
}

while((size=read(fd,buff,10))!=0)
{
if(size==-1)
{
perror("error in reading source file");
exit(EXIT_FAILURE);
}
size1=write(fd_destination,buff,size);
if(size1==-1)
{
perror("error in writing to destination");
exit(EXIT_FAILURE);
}

}
printf("file copied successfully!\n");
return 0;
}
