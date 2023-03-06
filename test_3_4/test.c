#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("hello world");
    fflush(stdout);
    sleep(1); 
    return 0;
}
