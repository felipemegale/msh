#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define BUFFSIZE 80

char** split(char*);
void printhelp();
void list(void);
void crtdir(char*);
void chgdir(char*);

int main()
{
    char *input = (char*) calloc (BUFFSIZE, sizeof(char));
    char *command, *param;
    int num;
	short option;
	printf("\nWelcome!\n\n");
	
	do
	{
		printf("~ ");
		
		fgets(input, BUFFSIZE, stdin);

        command = strtok(input, " ");

        // implementacao de listagem de conteudo
        if (strcmp(command, "list\n") == 0)
        {
            list();
            printf("\n");
        }

        // implementacao de criacao de diretorio
        else if ((strcmp(command, "crtdir") == 0) || (strcmp(command, "crtdir\n") == 0))
        {
            if (strcmp(command, "crtdir\n") == 0)
                printf("Directory must have a name!\n");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';
                crtdir(param);
            }
        }

        // implementacao de troca de diretorio
        else if((strcmp(command, "chgdir") == 0) || (strcmp(command, "chgdir\n") == 0))
        {
            if (strcmp(command, "chgdir\n") == 0)
                printf("You must specify where to go!\n");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)] = '\0';
                chgdir(param);
            }
        }

        else if (strcmp(command, "help\n")  == 0) printhelp();
        else if (strcmp(command, "quit\n") != 0) printf("Invalid command!\n\n");

	} while(strcmp(command, "quit\n"));

    printf("Goodbye! o/\n\n");
    return 0;
}

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
    {
        perror("Nem abriu kk");
    }
}

void crtdir(char *dirname)
{
    int status;
    status = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
    
    if (status != 0)
        printf("Directory creation failed.\n");
}

void chgdir(char *dirname)
{
    char *pwd;
    int extstat;
    
    getcwd(pwd, BUFFSIZE); // get full path to current dir
    
    /* concatenate destination directory */
    strcat(pwd, "/");
    strcat(pwd, dirname);
    strcat(pwd, "/");

    printf("Changing to %s\n", pwd);

    extstat = chdir(pwd);
    printf("CHGDIR exit status: %d\n", extstat);
}

void printhelp()
{
    printf("crtdir - Create dir\n"); // done
    printf("chgdir  - Change dir\n"); // 
    printf("list - List dir\n"); // done
    printf("15 - Create file\n");
    printf("20 - Delete file\n");
    printf("25 - Create symlink to file\n");
    printf("30 - Remove symlink to file\n");
    printf("35 - Show contents of a file\n");
    printf("40 - Create temporary text file\n");
    printf("help - Print this bunch of text\n");
    printf("100 - Quit\n");
}