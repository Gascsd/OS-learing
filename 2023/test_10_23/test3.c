#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();
    switch(pid)
    {
    case -1:
        printf("fork fail\n");
        exit(1);
    case 0:
        execl("/bin/ls", "ls", "-l", "-color", NULL);
        printf("execl fail\n");
        exit(1);
    default:
        wait(NULL);
        printf("ls completed!\n");
        exit(0);
    }
    return 0;
}
