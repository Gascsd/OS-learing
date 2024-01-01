#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define  FILE_NAME "log.txt"
int main()
{
    umask(0);
    int fd = open(FILE_NAME, O_RDONLY);
    if(fd < 0)
    {
        perror("open:");
        return 1;
    }
    dup2(fd, 0);//使用dup进行输入重定向（也就是替换fd为0的位置）
    char line[64];
    while(1)
    {
        printf(">");//输入提示
        char* ret = fgets(line, sizeof(line), stdin);
        if(ret == NULL)
            break;
        printf("%s\n",line);//打印stdin读取到的内容
    }
    return 0;
}
