#include <stdio.h>
#include <unistd.h>

int main()
{
    chdir("/home/zht");
    while(1)
    {
        printf("I am a process,pid:%d\n", getpid());
        sleep(1);
    }
    return 0;
}
