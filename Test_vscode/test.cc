#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

void Test()
{
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    set<int> s;
    for(auto& e : a)
    {
        s.insert(e);
    }
    for(auto& e : s)
    {
        //e++;
        cout << e << " ";
    }
    cout << endl;
}
void Test2()
{
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(0);
    for(auto e : us)
    {
        cout << e << " ";
    }
    cout << endl;
}
int main()
{
    Test2();
    cout << "hello vscode" << endl;
    cout << "hello vscode" << endl;
    cout << "hello vscode" << endl;
    cout << "hello vscode" << endl;
    cout << "hello vscode" << endl;
    return 0;
}