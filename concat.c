#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 120

int main(int argc, char *argv[])
{
    char tfh[BUFFSIZE] = "tmp-";
    char *filename = (char*) calloc (BUFFSIZE, sizeof(char));

    strcpy(filename, argv[1]);
    strcat(tfh, filename);

    printf("Filename: %s\n", tfh);

    return 0;
}