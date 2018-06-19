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

// displays the content of a file
void shwfctt(char *filename)
{
    int extopenstat, cnt;
    int lclbuff = BUFFSIZE * 12; // 12 chosen arbitrarily
    char *buffer = (char*) calloc (lclbuff, sizeof(char));
    
    extopenstat = open(filename, O_RDONLY);

    if (extopenstat >= 0)
        while ((cnt = read(extopenstat, buffer, lclbuff)) > 0)
            printf("%s", buffer);
    else
        printf("SHWFCTT exit status: %s\n", strerror(errno));
    
    close(extopenstat);
    
    free(buffer);
}