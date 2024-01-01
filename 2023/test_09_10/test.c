#include <stdio.h>


//结构体 声明
struct Student
{
    char sno[50];
    char name[20];
    double source;
};

int main()
{
    int a = 10;
    //类型名 变量名 （= 初始值）
    struct Student stu;
    scanf("%s", stu.name);
    char name[20] = "张三";
    //stu.name = name;
    scanf("%s", stu.sno);
    //stu.sno = "32103210";
    stu.source = 81.3;
    printf("学号:%s\n姓名:%s\n成绩:%lf\n",stu.sno, stu.name, stu.source);

    struct Student* pstu = &stu;
    printf("学号:%s\n姓名:%s\n成绩:%lf\n",pstu->sno, pstu->name, pstu->source);

    printf("test\n");
    return 0;
}