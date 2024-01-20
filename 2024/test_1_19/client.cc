#include "comm.hpp"

int main()
{
    key_t k = getKey();                     // 通过共同的pathname和proj_id构建一个相互通信的进程之间的key
    int shmid = getShm(k);                  // 通过创建的key获取指定的共享内存
    char *start = (char *)attachShm(shmid); // 将这段共享内存和当前进程地址空间关联

    // 使用共享内存通信
    const char *message = "hello server,我是另一个进程，正在和你通信"; // 通信信息
    pid_t id = getpid();
    int count = 1;
    while (true)
    {
        sleep(5);
        snprintf(start, MAX_SIZE, "%s[pid:%d][消息编号:%d]", message, id, count++); // 直接讲通信信息写到start中即可
    }

    delShm(shmid); // 使用完之后去关联
    return 0;
}