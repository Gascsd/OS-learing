#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>

#define NUM 1024//输入缓冲区大小
#define OPT_NUM 64//命令参数最大个数

#define NONE_REDIR 0
#define INPUT_REDIR 1
#define APPEND_REDIR 2
#define OUTPUT_REDIR 3
#define ERROR_REDIR 4
#define trimSpace(start) {\
    while(isspace(*start)) ++start;\
}while(0) //去空格的宏定义

char lineCommand[NUM];//输入缓冲区
char* argv[OPT_NUM];
int EXIT_CODE;

int redirType = NONE_REDIR;
char* redirFile = NULL;

void checkCommand(char* commands)
{
    assert(commands);
    char* start = commands;
    char* end = commands + strlen(commands);
    while(start < end)
    {
        if(*start == '>')
        {
            *start = '\0';
            ++start;
            if(*start == '>')
            {
                //append
                redirType = APPEND_REDIR;
                ++start;
            }
            else 
            {
                //output
                redirType = OUTPUT_REDIR;
            }
            trimSpace(start);
            redirFile = start;
            break;
        }
        else if(*start == '<')
        {
            //intput
            *start = '\0';
            ++start;
            trimSpace(start);
            //填写重定向信息（type和file）
            redirType = INPUT_REDIR;
            redirFile = start;
            break;
        }
        else  
        {
            ++start;
        }
    }
}

int main()
{
    while(1)//死循环，因为Shell要一只运行着
    {
        //初始化全局变量
        redirType = NONE_REDIR;
        redirFile = NULL;
        //打印输出命令提示符
        printf("[用户名@主机名 当前路径]$ ");
        fflush(stdout);//由于打印命令提示符的时候没有换行，所以这里手动刷新缓冲区
        //获取输入
        char* str = fgets(lineCommand, sizeof(lineCommand) - 1, stdin);//最后一个位置用于在极端情况下保证字符串内有'\0'
        assert(str);//判断合法性
        (void)str;
        lineCommand[strlen(lineCommand) - 1] = '\0';//消除行命令中的换行
        
        checkCommand(lineCommand);

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
            //用子进程来实现重定向的内容
            //但是子进程如何执行重定向是由父进程来告诉子进程的（如何告诉？redirType和redirFile）
            switch(redirType)
            {
                case NONE_REDIR:
                    break;//如果没有任何重定向的话就直接执行程序替换
                case INPUT_REDIR:
                {
                    int fd = open(redirFile, O_RDONLY);
                    if(fd < 0)
                    {//如果打开失败就直接返回
                        perror("open:");
                        exit(errno);
                    }
                    //使用dup2重定向
                    dup2(fd, 0);
                }
                break;
                case OUTPUT_REDIR:
                case APPEND_REDIR:
                {
                    int flags = O_WRONLY | O_CREAT;
                    if(redirType == OUTPUT_REDIR) flags |= O_TRUNC;
                    else flags |= O_APPEND;
                    int fd = open(redirFile, flags, 0666);
                    if(fd < 0)
                    {
                        perror("open:");
                        exit(errno);
                    }
                    dup2(fd, 1);
                }
                break;
                default:
                    printf("bug?\n");
            }

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
