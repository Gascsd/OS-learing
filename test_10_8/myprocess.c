#include <stdio.h>
#include <unistd.h>

int main()
{
    int id = fork();
    if(id == 0)
    {
        printf("我是一个子进程，id:%d\n", getpid());
    }
    else
    {
        printf("我是一个父进程，id:%d\n", getppid());
    }
    return 0;
}
