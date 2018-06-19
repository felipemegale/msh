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

// creates a file in current dir
void crtfile(char *filename)
{
    int extstat;

    mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;

    extstat = creat(filename, mode);

    if (extstat == -1)
        printf("CRTFILE exit status: %s\n", strerror(errno));

}