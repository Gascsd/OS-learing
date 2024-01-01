#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf\n");
    fputs("hello fputs\n", stdout);

    const char* msg = "hello write\n";
    write(1, msg, strlen(msg));    
    fork();
    return 0;
}
