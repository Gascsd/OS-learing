#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t id = fork();
    assert(id != -1);

    if(id == 0)
    {
        //子进程进行进程替换
        printf("child process is running...\n");
        //char* const argv[] = {
        //    "ls",
        //    "--color=auto",
        //    NULL
        //};
        //execvp("ls", argv);
        char* myval = (char*)"MYVAL=11223344";
        extern char** environ;
        putenv(myval);
		//execle("./myexec/myexec", "myexec", NULL, environ);    
        char* const argv[] = {
            (char*)"myexec",
            NULL 
        };
        execvpe("myexec", argv, environ);
        printf("exec fail...\n");
        exit(-1);//如果代码执行到此处，那么进程替换就是失败的，直接退出，退出码为-1
    }
    else 
    {
        //父进程等待子进程结束之后做回收
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if(ret == -1)
        {
            printf("wait fial\n");
        }
        else 
        {
            if(WIFEXITED(status))
            {
                //子进程正常退出
                printf("exit normal, exit code:%d\n", WEXITSTATUS(status));
            }
            else 
            {
                //子进程异常退出
                printf("exit error, exit signal:%d\n", status & 0x7F);
            }
        }
    }

    return 0;
}
