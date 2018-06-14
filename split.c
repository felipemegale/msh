#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 80

int main()
{
    char *string = (char*) calloc (BUFFSIZE, sizeof(char));
    char *token;
    char **splitted;

    fgets(string, BUFFSIZE, stdin);

    token = strtok(string, " ");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}