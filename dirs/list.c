#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

// lists the content of the current dir
void list(void)
{
    DIR *dp;
    struct dirent *ep;
    dp = opendir("./");

    if (dp != NULL)
    {
        while (ep = readdir(dp))
            puts(ep->d_name);
        (void) closedir(dp);
    }
    else
        perror("Coudld not open directory.\n");
}