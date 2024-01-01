#include<stdio.h>
#include<unistd.h>

int main()
{
    int cnt = 10;
    while(cnt)
    {
        printf("%2d\r",cnt--);
        usleep(500000);
        fflush(stdout);
    }
    return 0;
}
