#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("PATH:%s\n",getenv("PATH"));
    printf("PWD:%s\n",getenv("PWD"));
    printf("MYVAL:%s\n",getenv("MYVAL"));
    printf("我是一个测试程序\n");
}
