#include <stdio.h>
#include <stdlib.h>

#define ENV_NAME "PATH"

int main()
{
    printf("%s\n", getenv(ENV_NAME));
    return 0;
}
