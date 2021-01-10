#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 #include <stdlib.h>
int main()
{
    int fd;
    fd= open("desd.log",O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
    if(fd==-1)
    {
        perror("Error in opening the file");
        exit(EXIT_FAILURE);
    }
    int fs=write(fd,"RajeevJordan\n",13);
    if(fs==-1)
    {
        perror("Error in Writing\n");
        exit(EXIT_FAILURE);
    }
    close(fd);
}
