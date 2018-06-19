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

// removes a file in the current dir
void rmfile(char *filename)
{
    int extstat;

    extstat = remove(filename);
    
    if (extstat == -1)
        printf("RMFILE exit status: %s\n", strerror(errno));
}