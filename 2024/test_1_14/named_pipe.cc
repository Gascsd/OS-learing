#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#define PATHNAME "pipefile"

int main()
{
    //创建管道
    umask(0);
    int ret = mkfifo(PATHNAME, 0666);
    if(ret != 0)
    {
        perror("make named_pipe:");
        exit(-1);
    }
    std::cout << "named_pipe create success" << std::endl;

    return 0;
}