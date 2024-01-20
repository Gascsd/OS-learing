#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// 种随机数种子的一个宏，为了让随机数更随机，加上了一些处理
#define MakeSeed() srand((unsigned long)time(nullptr) ^ getpid() ^ 0x1234321 ^ rand() % 1234)

#define PROCSS_NUM 5 // 进程池中的进程个数

typedef void (*func_t)(); // 子进程要完成的任务函数指针

// 任务描述(这里是所有的任务)
void downLoadTask();
void ioTask();
void flushTask();

void loadTaskFunc(std::vector<func_t>& funcMap); // 加载任务清单