#include"process.h"

void ProcessOn() //函数的定义
{
    //ptrintf("hello process\n");
    int cnt = 0;
    char bar[NUM];
    char ch[] = {'-', '\\', '|', '/'};
    memset(bar, '\0', sizeof(bar));
    
    
    while(cnt <= 100)
    {
        printf("[%-100s][%-3d%%][%c]\r", bar, cnt, ch[cnt % 4]);
        fflush(stdout);
        bar[cnt++] = STYLE;
        usleep(10000);
    }
    printf("\n");
}
