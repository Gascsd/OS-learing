//C语言的文件操作

#include <stdio.h>
#include <iostream>
using namespace std;
#define FILE_NAME "log.txt"

int main()
{
  FILE* fp = fopen(FILE_NAME, "w+");
  if(fp == NULL)
  {
    perror("open file");
    return -1;
  }
  //cout << sizeof(FILE) << endl;
  for(int i = 0;i < 5; ++i)
  {
    fprintf(fp, "hello world %d\n", i);
  }

  char buffer[80];

  for(int i = 0;i < 5; ++i)
  {
    fscanf(fp, "%s", buffer);
    printf("%s", buffer);
  }

  fclose(fp);
  return 0;
}
