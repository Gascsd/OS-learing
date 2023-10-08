#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        //child process
        while(1)
        {
            printf("子进程！我的ID是%d, 我的PPID是%d, id是%d\n", getpid(), getppid(), id);
            sleep(1);
        }
    }
    else if(id > 0)
    {
        //parent process
        while(1)
        {
            printf("父进程！我的ID是%d, 我的PPID是%d, id是%d\n", getpid(), getppid(), id);
            sleep(2);
        }
    }
    else 
    {

    }
    sleep(2);
    return 0;
}
