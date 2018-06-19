#include <stdio.h>

void printhelp()
{
    printf("crtdir <dirname> - Create a directory\n");
    printf("chgdir <dirname> - Change to a directory\n");
    printf("list - Lists contents of current directory\n");
    printf("crtfile <filename> - Creates a file in the current directory\n");
    printf("rmfile <filename> - Deletes a file in the current directory\n");
    printf("crtslf <filename> <symlink name> - Creates symlink to file\n");
    printf("rmslf <file> - Removes symlink to file\n");
    printf("readslf <symlink name> - Prints where the symlink is pointing to\n");
    printf("shwfctt <filename> - Shows contents of a file\n");
    printf("crttmpf <filename> - Creates temporary text file\n");
    printf("help - Prints this somewhat useless text\n");
    printf("whoisresponsibleforthis - Prints the two YAWCS who wrote this crap\n");
    printf("quit - Quit\n\n");
}