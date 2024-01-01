#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>

#define NUM 1024//输入缓冲区大小
#define OPT_NUM 64//命令参数最大个数
char lineCommand[NUM];//输入缓冲区
char* argv[OPT_NUM];
int EXIT_CODE;
int main()
{
    while(1)//死循环，因为Shell要一只运行着
    {
        //打印输出命令提示符
        printf("[用户名@主机名 当前路径]$ ");
        fflush(stdout);//由于打印命令提示符的时候没有换行，所以这里手动刷新缓冲区
        //获取输入
        char* str = fgets(lineCommand, sizeof(lineCommand) - 1, stdin);//最后一个位置用于在极端情况下保证字符串内有'\0'
        assert(str);//判断合法性
        (void)str;
        lineCommand[strlen(lineCommand) - 1] = '\0';//消除行命令中的换行

        //命令解析（字符串切割）
        argv[0] = strtok(lineCommand, " ");
        int i = 1;

        if(argv[0] != NULL && strcmp(argv[0], "ls") == 0)//识别ls，自动加上颜色选项
        {
            argv[i++] = (char*)"--color=auto";
        }

        while(argv[i++] = strtok(NULL, " "));//使用字符串切割函数依次拿到每个参数
       
        if(argv[0] != NULL && strcmp(argv[0], "cd") == 0)
        {
            if(argv[1] != NULL)
            {
                chdir(argv[1]);
            }
            else 
            {
                printf("no such file or directory\n");
            }
            continue;
        }
        if(argv[0] != NULL && strcmp(argv[0], "echo") == 0)
        {
            if(strcmp(argv[1], "$?") == 0)
            {
                printf("%d\n", EXIT_CODE);
                EXIT_CODE = 0;
            }
            else 
            {
                printf("%s\n", argv[1]);
            }
            continue;
        }

        //创建子进程
        pid_t id = fork();
        if(id == -1)
        {
            perror("fork");
            exit(errno);
        }
        else if(id == 0)
        {
            //child
            //进程程序替换
            execvp(argv[0], argv);
            //执行到此处的时候，证明进程替换错误
            perror("exec:");
            exit(errno);
        }
        else 
        {
            //parent
            //进程等待
            int status = 0;//退出状态
            pid_t ret = waitpid(id, &status, 0);//阻塞等待
            EXIT_CODE = (status >> 8) & 0xFF;
            if(ret == -1)
            {
                perror("wait fail");
                exit(errno);
            }
        }
    }
    return 0;
}
