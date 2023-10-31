#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        //第一个子进程
        while(1)
        {
            printf("daughter...\n");
            sleep(1);
        }
    }
    else 
    {
        //父进程
        pid_t id2 = fork();
        if(id2 == 0)
        {
            //第二个子进程
            while(1)
            {
                printf("son...\n");
                sleep(1);
            }
        }
        else 
        {
            //父进程
            while(1)
            {
                printf("parent...\n");
                sleep(1);
            }
        }
    }
    return 0;
}
