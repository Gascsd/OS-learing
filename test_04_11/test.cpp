#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    cout << "&a=" << &a << endl;
    cout << "&a=" << &a << endl;
    int* c = (int*)malloc(sizeof(int)*4);
    int* d = (int*)malloc(sizeof(int)*4);
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;
    return 0;
}
