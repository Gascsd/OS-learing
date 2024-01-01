#include <stdio.h>
#define FILENAME "log.txt"

int main()
{
    FILE *fp = fopen(FILENAME, "w");
    if(NULL == fp)
    {
        perror("fopen");
        return 1;
    }

    //char buffer[128] = {0};
   
  

    // cout << "open success" << endl;
    int cnt = 5;
    while(cnt--)
    {
    //    cout << "write sucess" << endl;
        fprintf(fp, "hello world! %d\n", cnt);
    }
    return 0;
}
