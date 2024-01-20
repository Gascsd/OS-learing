#include "header.h"

class subEp // EndPoint
{
public:
    subEp(pid_t subId, int writeFd)
        : subId_(subId), writeFd_(writeFd)
    {
        char nameBuffer[1024];
        snprintf(nameBuffer, sizeof nameBuffer, "process-%d[pid(%d)-fd(%d)]", num++, subId_, writeFd_);
        name_ = nameBuffer;
    }

public:
    static int num;    // 创建的进程的唯一标识符（序号）
    std::string name_; // 子进程名字
    pid_t subId_;      // 子进程pid
    int writeFd_;      // 父进程的该管道写入文件描述符
};
int subEp::num = 0; // 初始化静态成员变量

int recvTask(int readFd) // 读取管道内的信息（任务码）
{
    int code = 0;
    ssize_t ret = read(readFd, &code, sizeof code);
    if (ret == 4) // 读取到的是4byte（一个整形）读取成功
        return code;
    else if (ret <= 0)
        return -1;
    else
        return 0;
}

void sendTask(const subEp &process, int taskNum) // 给指定的子进程分配任务码
{
    std::cout << "send task num: " << taskNum << " send to -> " << process.name_ << std::endl;
    int ret = write(process.writeFd_, &taskNum, sizeof(taskNum));
    assert(ret == sizeof(int));
    (void)ret;
}

void createSubProcess(std::vector<subEp> &subs, std::vector<func_t> &funcMap)
{
    for (int i = 0; i < PROCSS_NUM; ++i)
    {
        int fds[2];
        int n = pipe(fds);
        assert(n == 0);
        (void)n; // 这里由于assert只会在debug模式下使用，在release模式下不执行，所以加上一句使用变量n的无影响的代码，用于去掉一些警告：变量n未使用
        pid_t id = fork();
        if (id == 0)
        {
            // 子进程读取父进程写入管道的内容（分配的任务）
            // 子进程关闭写端，父进程关闭读端
            close(fds[1]);
            while (true)
            {
                // 子进程处理任务
                int commandCode = recvTask(fds[0]); // 读取管道内容获取命令码
                // 完成任务
                if (commandCode >= 0 && commandCode <= funcMap.size())
                {
                    // 任务码无误
                    funcMap[commandCode](); // 调用任务函数
                }
                else if (commandCode == -1)
                    break; // 任务码出现问题，退出进程
            }
            exit(0); // 处理完成退出
        }
        // 下面都是父进程会执行的代码
        close(fds[0]);                                // 父进程关闭读端
        subs.push_back(std::move(subEp(id, fds[1]))); // 使用子进程pid和父进程写入该父子进程之间管道的写端fd构建subEp对象，move成右值（将亡值）尾插
    }
}
void loadBlanceContrl(std::vector<subEp> &subs, std::vector<func_t> &funcMap, int count)
{
    int processNum = subs.size();
    int taskNum = funcMap.size();
    bool forever = (count == 0 ? true : false);

    while (true)
    {
        // 1. 选择一个子进程（随机数）
        int subIdx = rand() % processNum;
        // 2. 选择一个任务
        int taskIdx = rand() % taskNum;
        // 3. 任务发给选择的进程
        sendTask(subs[subIdx], taskIdx);
        sleep(1);
        if (!forever)
        {
            count--;
            if (count == 0)
                break;
        }
    }
    //任务完成后关闭和该子进程通信的写端 write close -> read 0
    for(int i = 0; i < processNum; ++i)
    {
        close(subs[i].writeFd_);
    }
}
void waitProcess(std::vector<subEp> &processes)
{
    int processNum = processes.size();
    for (int i = 0; i < processNum; ++i)
    {
        waitpid(processes[i].subId_, nullptr, 0);
        std::cout << "wait sub process success ..." << processes[i].subId_ << std::endl;
    }
}
int main()
{
    MakeSeed(); // 随机数种子
    // 加载方法表
    std::vector<func_t> funcMap;
    loadTaskFunc(funcMap);

    // 创建子进程，并且维护好父子进程通信信道
    std::vector<subEp> subs;
    createSubProcess(subs, funcMap);

    // 只有父进程会执行完函数后退出，到当前位置
    int taskCnt = 3;                          // 一共要完成的任务个数，0表示永远进行
    loadBlanceContrl(subs, funcMap, taskCnt); // 负载均衡的加载任务给所有进程

    waitProcess(subs); // 回收（等待）子进程

    return 0;
}
