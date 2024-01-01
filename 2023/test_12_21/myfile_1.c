#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



//int main()
//{
//    printf("stdin:%d\n", stdin->_fileno);
//    printf("stdout:%d\n", stdout->_fileno);
//    printf("stderr:%d\n", stderr->_fileno);
//    return 0;
//}




//#define FILE_NAME(number) "log"#number".txt"
//
//int main()
//{
//    int  fd0 = open(FILE_NAME(0), O_WRONLY | O_CREAT | O_TRUNC, 0666);
//    int  fd1 = open(FILE_NAME(1), O_WRONLY | O_CREAT | O_TRUNC, 0666);
//    int  fd2 = open(FILE_NAME(2), O_WRONLY | O_CREAT | O_TRUNC, 0666);
//    int  fd3 = open(FILE_NAME(3), O_WRONLY | O_CREAT | O_TRUNC, 0666);
//    int  fd4 = open(FILE_NAME(4), O_WRONLY | O_CREAT | O_TRUNC, 0666);
//    printf("fd0=%d\n", fd0);
//    printf("fd1=%d\n", fd1);
//    printf("fd2=%d\n", fd2);
//    printf("fd3=%d\n", fd3);
//    printf("fd4=%d\n", fd4);
//    return 0;
//}
//


//#define FILE_NAME "log.txt"
//
//int main()
//{
//    umask(0);
//    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0666);//以写的方式打开，如果文件不存在就创建文件
//    //int fd = open(FILE_NAME, O_RDONLY);//以只读的方式打开，如果文件不存在就创建文件
//    if(fd < 0)
//    {
//        perror("open");
//        return 1;
//    }
//    //printf("%s打开成功\n", FILE_NAME);
//
//    //向文件中写入
//    const char* msg = "hello world\n";//这里更改了写入的内容
//    int cnt = 5;
//    while(cnt--)
//    {
//        write(fd, msg, strlen(msg));//这里写入的长度要不要+1 ？
//    }
//    //从文件中读取
////    char buffer[512];
////    while(read(fd, buffer, sizeof(buffer) - 1) != 0)
////    {
////        printf("%s\n", buffer);
////    }
////
//    int ret = close(fd);
//    if(ret == -1)
//    {
//        perror("close");
//        return 2;
//    }
//    //printf("%s关闭成功\n", FILE_NAME);
//    return 0;
//}
