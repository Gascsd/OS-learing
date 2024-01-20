#include "comm.hpp"

int main()
{
    key_t k = getKey();                     // 通过共同的pathname和proj_id构建一个相互通信的进程之间的key
    int shmid = createShm(k);               // 通过创建的key创建一段共享内存
    char *start = (char *)attachShm(shmid); // 将这段共享内存和当前进程地址空间关联

    // 使用共享内存通信
    while (true)
    {
        std::cout << "client say# " << start << std::endl; // 这里可以直接读取通信信息，因为地址相同
        struct shmid_ds ds;
        shmctl(shmid, IPC_STAT, &ds); //    获取shmid的相关信息
        printf("获取属性:size:%d,pid:%d,myself:%d\n", ds.shm_segsz, ds.shm_cpid);
        sleep(1);
    }

    delShm(shmid); // 使用完之后去关联
    delShm(shmid); // 谁创建的共享内存谁来释放
    return 0;
}