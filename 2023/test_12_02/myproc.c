#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int cnt = 0;
    while(1)
    {
        printf("%d:%s\n", cnt, strerror(cnt));
        cnt++;
        if(cnt == 135) break;
    }
    return 0;
}
