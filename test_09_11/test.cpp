#include <iostream>
#include <unordered_map>
using namespace std;

// int main()
// {
//     // 10个三好学生名额分配到 7 个班级，每个班级至少有一个名额，一共有()不同的分配方策
//     // int count = 0;
//     // for(int a = 1; a <= 10; ++a)
//     // {
//     //     for(int b = 1; b <= 10; ++b)
//     //     {
//     //         for(int c = 1; c <= 10; ++c)
//     //         {
//     //             for(int d = 1; d <= 10; ++d)
//     //             {
//     //                 for(int e = 1; e <= 10; ++e)
//     //                 {
//     //                     for(int f = 1; f <= 10; ++f)
//     //                     {
//     //                         for(int g = 1; g <= 10; ++g)
//     //                         {
//     //                             if(a+b+c+d+e+f+g == 10)
//     //                             {
//     //                                 count++;
//     //                             }
//     //                         }
//     //                     }
//     //                 }
//     //             }
//     //         }
//     //     }
//     // }
//     // cout << count << endl;

//     //有五副不同颜色的手套（共10 只，每副手套左右各1只)从中取 6只手套，请问恰好能配成两副于套的不向取法有（) 种
//     int count = 0;
//     Solution(count);
//     cout << count << endl;
//     return 0;
// }


// #include <cstdlib>
// #include <iostream>
// using namespace std;

//  char encoder [26] = {'C', 'S', 'P', 0};
//  char decoder [26];

//  string st;

//  int main() 
//  {
//     int k = 0;
//     for (int i = 0; i < 26; ++i)
//         if(encoder[i] != 0) ++k;
//     for (char x = 'A'; x <= 'Z'; ++x) {
//         bool flag = true;
//         for (int i = 0; i < 26; ++i)
//             if(encoder[i] == x) {
//                 flag = false;
//                 break;
//             }
//             if (flag) {
//                 encoder[k] = x;
//                 ++k;
//             }
//     }
//     for (int i = 0; i < 26; ++i)
//         decoder[encoder[i] - 'A'] = i +'A';
//     cin >> st;
//  for (int i = 0; i << st.length(); ++i)
// st[il = decoder [st[i] - 'A'];
// cout << st;
// return 0;



// int main()
// {
//     int a = -1 / 2;
//     cout << a << " " << -1 / 2.0 << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int* p = arr;
    for(int i = 0; i < 10; ++i)
    {
        cout << *p << " ";
        p++;
    }
    return 0;
}