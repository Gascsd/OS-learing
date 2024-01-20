#include "header.h"

//任务列表
void downLoadTask()
{
    std::cout << getpid() << ":下载任务\n" << std::endl;
    sleep(1);
}

void ioTask()
{
    std::cout << getpid() << ":IO任务\n" << std::endl;
    sleep(1);
}
void flushTask()
{
    std::cout << getpid() << ":刷新任务\n" << std::endl;
    sleep(1);
}

void loadTaskFunc(std::vector<func_t>& funcMap) // 加载任务清单
{
    //funcMap.emplace_back({downLoadTask, ioTask, flushTask});
    funcMap.push_back(downLoadTask);
    funcMap.push_back(ioTask);
    funcMap.push_back(flushTask);
}
