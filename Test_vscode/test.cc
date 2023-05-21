#include <iostream>
#include <set>

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

int main()
{
    Test();
    // cout << "hello vscode" << endl;
    // cout << "hello vscode" << endl;
    // cout << "hello vscode" << endl;
    // cout << "hello vscode" << endl;
    // cout << "hello vscode" << endl;
    return 0;
}