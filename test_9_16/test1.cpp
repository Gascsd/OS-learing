#include <stdio.h>



union Un 
{
    int i;
    char c; 
};
union Un un;
// 下面输出的结果是一样的吗? 
void test()
{
  printf("%d\n", &(un.i)); 
  printf("%d\n", &(un.c));
  //下面输出的结果是什么? 
  un.i = 0x11223344; 
  un.c = 0x55; 
  printf("%x\n", un.i);
}

#include <iostream>
using namespace std;

enum Sex
{
  man,
  woman = 5,
  secrte = 5
};

//1. 枚举类型中，如果我们不给成员赋值，默认从第一个成员开始，从0依次向下赋值
//2. 如果有赋值，从赋值的成员处开始，依次往下加
//3. 只要成员有赋值，那么他的值就是赋的那个值
//4. 所有的值的推演都是建立在没有值的基础上的，如果有赋值，我就按照赋值的来
void test1()
{
  Sex s1 = man;
  s1 = woman;

  //s1 = 5;//不能这样赋值
  // 枚举变量的赋值只能赋枚举过的内容
  cout << s1 << endl;
}

class StackOnly
{
public:
  static StackOnly CreateObj()
  {
      return StackOnly();
  }
private:
    StackOnly(){}
    StackOnly(const StackOnly&) = delete;
};
void test2()
{
    static StackOnly obj = StackOnly::CreateObj();

}


int main(){
  //test();
  test2();
  return 0;
}

