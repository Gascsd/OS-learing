#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void TODO() // 做其他的事情
{
    printf("do something without the processes......\n");
}

int main()
{
    pid_t id = fork();
    if(id == -1)
    {
        perror("create process fail:");
        exit(-1);
    }
    else if(id == 0)
    {
        //parent
        int cnt = 3;
        while(cnt--)
        {
            printf("child process,pid:%d, ppid:%d,cnt:%d\n", getpid(), getppid(), cnt);
            sleep(1);
        }
        exit(1);
    }
    else 
    {
        //parent
        int status = 0;
        while(1)//轮询
        {
            pid_t ret = waitpid(id, &status, WNOHANG); // 非阻塞等待
            if(ret == -1) // 调用失败
            {
                printf("wait fail\n");
                exit(-2);
            }
            else if(ret == 0) // 调用成功，但是子进程未结束
            {
                printf("wait success, but child process wasn't exit\n");
                TODO();
            }
            else //ret == id 调用成功，子进程退出
            {
                printf("wait success, child exited\n");
                break;
            }
            sleep(1);
        }

        if(WIFEXITED(status)) // 正常退出
        {
            printf("exit normal, exit code: %d\n", WEXITSTATUS(status));
        }
        else 
        {
            printf("exit error, exit signal:%d\n", WIFEXITED(status));
        }
    }
    return 0;
}


