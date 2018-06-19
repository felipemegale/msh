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

// creates a temporary file
void crttmpf(char *filecontent)
{
    FILE *tfp;

    tfp = tmpfile();

    if (tfp == NULL)
        printf("Could not create file. Unexpected behavior.\n");
    else if (filecontent != NULL)
    {
        fwrite(filecontent, sizeof(char), BUFFSIZE, tfp);
        // fclose(tfp);
    }
    else
    {
        fwrite("TMP FILE HEADER\n", sizeof(char), strlen("TMP FILE HEADER\n"), tfp);
        // fclose(tfp);
    }

    free(tfp);

}