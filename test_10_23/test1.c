#include <stdio.h>
#include <unistd.h>

int main()
{
        pid_t id1 = fork();
        if(id1 > 0)
        {
            //父进程
            pid_t id2 = fork();
            if(id2 > 0)
            {
                //父进程
                printf("a");
            }
            else 
            {
                //子进程2
                printf("c");
            }
        }
        else 
        {
            //子进程1
            printf("b");
        }
    return 0;   
}
