#include "header.hpp"

// client创建管道，向管道中写入数据，server读取

int main()
{
    bool ret = createPipe(PIPE_NAME);
    if (ret == false)
    {
        exit(-1);
    }

    int Wfd = open(PIPE_NAME, O_WRONLY);
    if (Wfd == -1)
    {
        perror("open pipe fail:");
        exit(-2);
    }

    // 通过输入，循环向管道中写入数据
    char buffer[1024];
    while (true)
    {
        std::cout << "请输入通信信息# ";
        fgets(buffer, sizeof buffer, stdin);
        if(strlen(buffer) > 0)
        {
            buffer[strlen(buffer) - 1] = 0;//去掉输入的结尾字符'\n'
        }
        ssize_t ret = write(Wfd, buffer, strlen(buffer));
        if(ret != strlen(buffer))
        {
            std::cout << "数据写入异常" << std::endl;
            break;
        }
    }
    close(Wfd);
    removePipe(PIPE_NAME);
    return 0;
}