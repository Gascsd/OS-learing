#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t id = fork();
    if(id > 0)
    {
        //parent
        printf("I am parent process, pid:%d, ppid:%d\n", getpid(), getppid());
        sleep(3);
        exit(0);
    }
    else if(id == 0)
    {
        //child
        while(1)
        {
            printf("I am child process, pid:%d, ppid:%d\n", getpid(), getppid());
            sleep(1);
        }
    }
    return 0;
}
