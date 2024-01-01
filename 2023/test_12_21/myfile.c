#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_NAME "log.txt"

int main()
{
    close(1);

    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd < 0)
    {
        perror("open:");
        return 1;
    }
    
    printf("fd=%d\n", fd);
    fflush(stdout);
    close(fd);
    return 0;
}
