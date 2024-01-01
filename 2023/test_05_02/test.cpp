#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void func() { cout << "Base::func" << endl; }
};
class Drive : public Base 
{
public:
    virtual void func() { cout << "Drive::func" << endl; }
};
void Test()
{
    Base ba;
    int a = 10;
    int* b = new int(20);
    static int c = 30;
    const char* d = "aaaa";
    cout << "栈：" << &a << endl;
    cout << "堆："<< b << endl;
    cout << "静态区" << &c << endl;
    cout << "代码段" << (void*)d << endl;
    cout << "虚表地址" << (void*)(*(int*)&ba) << endl;
}
int main()
{
    Test();
    return 0;
}
