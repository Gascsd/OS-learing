#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        //子进程
        while(1)
        {
            printf("子进程，pid:%d, ppid:%d, id:%d\n", getpid(), getppid(), id);
            sleep(1);
        }
    }
    else 
    {
        //父进程
        while(1)
        {
            printf("父进程，pid:%d, ppid:%d, id:%d\n", getpid(), getppid(), id);
            sleep(2);
        }
    }
    return 0;
}
