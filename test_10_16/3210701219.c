#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 10;
    scanf("%d", &n);
    int i = 0;
    int* p = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; ++i)
    {
        p[i] = i;
    }
    for(i = 0; i < n; ++i)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}
