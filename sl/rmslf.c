#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFSIZE 120

// removes symbolic link to specified file
void rmslf(char *filename)
{
    int extstat;

    extstat = unlink(filename);

    if (extstat != 0)
        printf("RMSLF exit status: %s\n", strerror(errno));
}