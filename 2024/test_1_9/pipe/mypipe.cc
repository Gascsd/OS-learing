#include <iostream>
#include <unistd.h>
#include <cassert>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fds[2];
    int ret = pipe(fds);
    assert(ret == 0);

    // 创建子进程
    int id = fork();
    if (id == 0)
    {
        // 子进程
        // 子进程向管道中写数据，关闭读端
        close(fds[0]);
        // 通信
        const char *s = "这里是子进程，正在向父进程发送信息";
        int cnt = 0;
        while (true)
        {
            cnt++;
            char buffer[1024];
            snprintf(buffer, sizeof buffer, "child->parent say:%s[%d][pid:%d]", s, cnt, getpid());
            write(fds[1], buffer, strlen(buffer));
            if(cnt == 10) break;
            sleep(1); // 每秒写一次
        }
        close(fds[1]); // 子进程退出前关闭写端
        exit(0);
    }
    // 父进程
    // 父进程从管道中读数据，关闭写端
    close(fds[1]);
    // 通信
    while(true)
    {
        char buffer[1024];
        ssize_t s = read(fds[0], buffer, sizeof(buffer) - 1);
        if(s > 0) 
        {
            buffer[s] = 0;
            std::cout << "Get Massage# " << buffer << "| mypid:" << getpid() << std::endl;
        }
        else if(s == 0)
        {
            std::cout << "read file end" << std::endl;
            break;
        }
        else
        {
            std::cout << "read error" << std::endl;
            break;
        }
    }
    ret = waitpid(id, nullptr, 0);
    assert(ret == ret);

    close(fds[0]);
    return 0;
}