#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	string s1("hello wordl");
    string s2(s1);
    printf("写时拷贝前，共享内存\n");
    printf("s1:%p\n", s1.c_str());
    printf("s2:%p\n", s2.c_str());
    s2 += '!';
    printf("写时拷贝后，内存不共享\n");
    printf("s1:%p\n", s1.c_str());
    printf("s2:%p\n", s2.c_str());
	return 0;
}
