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

// changes to the specified dir
void chgdir(char *dirname)
{
    char *pwd = (char*) calloc (BUFFSIZE, sizeof(char));
    int extstat;

    getcwd(pwd, BUFFSIZE); // get full path to current dir
    
    /* concatenate destination directory */
    strcat(pwd, "/");
    strcat(pwd, dirname);
    strcat(pwd, "/");

    extstat = chdir(pwd);

    if (extstat != 0)
        printf("CHGDIR exit status: %s\n", strerror(errno));

    free(pwd);
}