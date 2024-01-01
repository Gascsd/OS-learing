#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string sno;
    string name;
    double source;
};


struct A
{
    char b;
    int c;
    char a;
};

A a;


// int main()
// {
//     // Student stu, stu1;
//     // cin >> stu.name >> stu.sno >> stu.source;
//     // //cout << stu;//为什么不能运行
//     // //swap(stu, stu1);//为什么能够运行（模版、泛型编程）
//     // cout << "姓名：" << stu.name << endl << "学号：" << stu.sno<< endl \
//     //  << "成绩" << stu.source<< endl << endl;
    
//     // Student* p = &stu;
//     // cout << p->name << p->sno << p->source;
//     int x;
//     //cout << sizeof(int) << endl;
//     //cout << sizeof(x) << endl;
//     cout << sizeof(A) << " " << sizeof(a) << endl;
//     //cout << sizeof(char) << endl;
//     return 0;
// }


namespace my
{
    class string
    {
    private:
        char* _str;
        int _size;
        int _capacity;
    };
}

int main()
{
    cout << sizeof(my::string) << endl;
    return 0;
}