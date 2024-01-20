#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPE_NAME "/tmp/named_pipe"

bool createPipe(const char *pathname)
{
    umask(0);
    int ret = mkfifo(pathname, 0666);
    if (ret != 0)
    {
        perror("make named_pipe error:");
        return false;
    }
    return true;
}

void removePipe(const char *pathname)
{
    unlink(pathname);
}