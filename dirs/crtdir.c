#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// creates a dir with the specified name
void crtdir(char *dirname)
{
    int extstat;
    extstat = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
    
    if (extstat != 0)
        printf("CRTDIR exit status: %s\n", strerror(errno));
}