#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *input = argv[1];
    char *result;
    
    getcwd(result, 80);
    
    strcat(result, "/");
    strcat(result, input);
    
    printf("%s\n", result);
    return 0;
}