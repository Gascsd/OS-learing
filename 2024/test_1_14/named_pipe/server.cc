#include "header.hpp"

int main()
{
    int Rfd = open(PIPE_NAME, O_RDONLY);
    if (Rfd == -1)
    {
        perror("open pipe fail:");
        exit(-3);
    }
    char buffer[1024];
    while (true)
    {
        ssize_t ret = read(Rfd, buffer, sizeof(buffer) - 1);
        if (ret > 0)
        {
            buffer[ret] = 0;
            std::cout << "server端读取到内容: " << buffer << std::endl;
        }
        else if(ret == 0)
        {
            std::cout << "客户端已退出,通信结束" << std::endl;
            break;
        }
        else
        {
            std::cout << "err string: " << strerror(errno) << std::endl;
            break;
        }
    }
    close(Rfd);
    return 0;
}