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

// reads the content of a symbolic link
void readslf(char *slname)
{
    char *buffer = NULL;
    int nchars;

    buffer = (char*) realloc(buffer, BUFFSIZE);
    nchars = readlink(slname, buffer, BUFFSIZE);

    strcat(slname, "\0");

    if (nchars < 0)
        free(buffer);
    else if (nchars <= BUFFSIZE)
        printf("%s\n", buffer);

    free(buffer);
}