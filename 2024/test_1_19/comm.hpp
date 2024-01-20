#pragma once
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <iostream>

#define PATHNAME "."  // 使用当前目录作为项目目录
#define PROJ_ID 0x66  // 随机的项目id
#define MAX_SIZE 4096 // 创建的共享内存大小

key_t getKey() // 封装获取key的函数
{
    key_t k = ftok(PATHNAME, PROJ_ID);
    if (k == -1)
    {
        std::cerr << errno << " : " << strerror(errno) << std::endl;
        exit(1);
    }
    return k;
}

int getShmHelper(key_t key, int flags) // 封装通过key来获取shmid的函数
{
    int shmid = shmget(key, MAX_SIZE, flags);
    if(shmid < 0)
    {
        std::cerr << errno << " : " << strerror(errno) << std::endl;
        exit(2);
    }
    return shmid;
}

int getShm(key_t key) // 用于找到已经创建的共享内存的shmid，所以传入的选项只有IPC_CREAT，不关心以前是否创建
{
    return getShmHelper(key, IPC_CREAT);
}

int createShm(key_t key) // 用于创建，所以传入的选项中有IPC_EXCL，表示如果遇到冲突就创建失败
{
    return getShmHelper(key, IPC_CREAT | IPC_EXCL | 0666); // 0666表示创建的共享内存的权限
}

void delShm(int shmid)
{
    if(shmctl(shmid, IPC_RMID, nullptr) == -1)// 这里不需要获取信息，传入nullptr即可
    {
        std::cerr << errno << " : " << strerror(errno) << std::endl;
    }
}

void *attachShm(int shmid)
{
    void *mem = shmat(shmid, nullptr, 0);
    if((long long)mem == -1L) // 这里由于我们的机器是64位的，所以一个地址占8个字节，所以需要转成long long类型判断是否正确关联
    {
        std::cerr << errno << " : " << strerror(errno) << std::endl;
        exit(3);
    }
    return mem;
}

void detachShm(void* start)
{
    if(shmdt(start) == -1)
    {
        std::cerr << errno << " : " << strerror(errno) << std::endl;
    }
}