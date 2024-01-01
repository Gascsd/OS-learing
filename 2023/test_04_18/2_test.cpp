#include <iostream>
#include <string>
#include <sys/time.h>
using namespace std;
long getcurrenttick()
{
    long tick ;
    struct timeval time_val;
    gettimeofday(&time_val , NULL);
    tick = time_val.tv_sec * 1000 + time_val.tv_usec / 1000 ;
    return tick;
}

int main()
{
    string s(1024*1024*10, 'x');
    long begin = getcurrenttick();
    for(int i = 0; i < 100; i++)
    {
        string tmp = s;
    }
    int end = getcurrenttick();

    cout << end - begin << endl;
    return 0;
}
