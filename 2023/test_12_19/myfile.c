#include <stdio.h>
#define FILE_NAME "log.txt"
int main()
{
    // fopen的返回值类型是FILE*，返回一个文件指针，打开失败返回NULL
    FILE* fp = fopen(FILE_NAME, "w+");//fopen传参数：1.文件名 2.打开方式："w"只写, "r"只读, "a"追加， "w+"读写, "r+"读写, "a+"追加读写
    if(fp == NULL)
    {
        perror("open");//打印失败原因
        return 1;
    }
    else 
    {
        printf("%s打开成功\n", FILE_NAME);
    }

    //写入/读取


    //文件打开了就需要关闭
    int ret = fclose(fp);//fclose传参数：FILE*类型，要关闭的文件指针
    //fclose的返回值类型int，如果关闭成功返回0，关闭失败返回EOF
    if(ret == 0)
    {
        printf("%s关闭成功\n", FILE_NAME);
    }
    else 
    {
        perror("关闭失败");//打印失败原因
        return 2;
    }
    return 0;
}
