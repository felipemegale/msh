#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// creates a symbolic link to a file
void crtslf(char *oldname, char *newname)
{
    int extstat;

    extstat = symlink(oldname, newname);

    if (extstat != 0)
        printf("CRTSLF exit status: %s\n", strerror(errno));
}