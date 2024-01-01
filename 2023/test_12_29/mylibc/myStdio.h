#pragma once 

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define SIZE 1024 // 缓冲区容量

// 缓冲区刷新策略
#define SYNC_NOW 1
#define SYNC_LINE 2
#define SYNC_FULL  4

typedef struct _FILE //定义的FILE结构体
{
    int fileno;           //文件描述符
    int flag;             //缓冲区刷新方式
    char buffer[SIZE];    //缓冲区
    int cap;              //缓冲区容量
    int size;             //缓冲区写入的数据大小
}FILE_;

//这里我们自己实现的函数和结构体在后面加了下划线
FILE_ *fopen_(const char* path_name, const char* mode);
void fclose_(FILE_* fp);
void fflush_(FILE_* fp);
void fwrite_(const void *ptr, int num, FILE_* fp);
