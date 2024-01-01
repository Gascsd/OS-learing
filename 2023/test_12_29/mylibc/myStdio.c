#include "myStdio.h"

FILE_ *fopen_(const char* path_name, const char* mode)
{
    int flags = 0; // 打开方式
    int defaultMode = 0666; // 默认的创建文件权限
    //设置打开的方式
    if(strcmp(mode, "r") == 0) 
    {
        flags |= O_RDONLY;
    }
    else if(strcmp(mode, "w") == 0)
    {
        flags |= (O_WRONLY | O_CREAT | O_TRUNC);
    }
    else if(strcmp(mode, "a") == 0)
    {
        flags |= (O_WRONLY | O_CREAT | O_APPEND);
    }
    else 
    {
        //do nothing
    }
    //按照不同方式打开文件并记录文件的fd
    int fd = 0;
    if(flags & O_RDONLY) // 只读
        fd = open(path_name, flags);
    else //可能要创建
        fd = open(path_name, flags, defaultMode);
    if(fd < 0)
    {
        //文件打开失败
        char* str = strerror(errno);
        write(2, str, strlen(str));
        return NULL;
    }
    //文件打开成功，构造FILE*对象并填充内容
    FILE_* fp = (FILE_*)malloc(sizeof(FILE_));
    if(fp == NULL)
    {
        char* str = strerror(errno);
        write(2, str, strlen(str));
        return NULL;
    }
    fp->fileno = fd;
    fp->cap = SIZE;
    fp->size = 0;
    memset(fp->buffer, 0, SIZE);
    fp->flag = SYNC_LINE;
    return fp;
}

void fflush_(FILE_* fp)
{
    //如果缓冲区有内容的话执行写入
    if(fp->size > 0)
    {
        write(fp->fileno, fp->buffer, fp->size);
        fp->size = 0;
        fsync(fp->fileno);
    }
}

void fclose_(FILE_* fp)
{
    //刷新缓冲区
    fflush_(fp);
    //关闭文件
    close(fp->fileno);
    //释放FILE结构体
    free(fp);
    fp = NULL;
}
void fwrite_(const void *ptr, int num, FILE_* fp)
{
    //写到缓冲区(本质上是拷贝，吧数据从ptr中拷贝到fp->buffer)
    memcpy(fp->buffer + fp->size, ptr, num);
    fp->size += num;
    //执行刷新策略
    if(fp->flag & SYNC_NOW) //无缓冲
    {
        if(fp->size != 0)
        {
            write(fp->fileno, fp->buffer, fp->size);
            fp->size = 0;//清空缓冲区
        }
    }
    else if(fp->flag & SYNC_LINE) // 行缓冲
    {
        if(fp->buffer[fp->size - 1] == '\n') //这里不考虑 abcd\nefg
        {
            write(fp->fileno, fp->buffer, fp->size);
            fp->size = 0;//清空缓冲区
        }
    }
    else if(fp->flag & SYNC_FULL) // 全缓冲
    {
        if(fp->size == fp->cap)
        {
            write(fp->fileno, fp->buffer, fp->size);
            fp->size = 0;//清空缓冲区
        }
    }
    else 
    {
        //do nothing
    }
}
