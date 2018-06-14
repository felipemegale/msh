#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 80

char** split(char*);
void printhelp();
void list(void);
void crtdir(char*);
void chgdir(char*);
void crtfile(char*);
void rmfile(char*);
void crtslf(char*, char*);
void readslf(char*);
void rmslf(char*);

int main()
{
    char *input = (char*) calloc (BUFFSIZE, sizeof(char));
    char *command, *param, *oparam;
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
        else if ((strcmp(command, "chgdir") == 0) || (strcmp(command, "chgdir\n") == 0))
        {
            if (strcmp(command, "chgdir\n") == 0)
                printf("You must specify where to go!\n");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';
                chgdir(param);
            }
        }

        // implementacao de criacao de arquivo
        else if ((strcmp(command, "crtfile") == 0) || (strcmp(command, "crtfile\n") == 0))
        {
            if (strcmp(command, "crtfile\n") == 0)
                printf("A file must have a name!\n");
            else
            {    
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';
                crtfile(param);
            }
        }

        // implementacao da remocao de arquivo
        else if ((strcmp(command, "rmfile") == 0) || (strcmp(command, "rmfile\n") == 0))
        {
            if (strcmp(command, "rmfile\n") == 0)
                printf("A file name must be specified!\n");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';
                rmfile(param);
            }
        }

        // implementacao da criacao de link simbolico
        else if ((strcmp(command, "crtslf") == 0) || (strcmp(command, "crtslf\n") == 0))
        {
            if (strcmp(command, "crtslf\n") == 0)
                printf("A file name must be specified!\n");
            else
            {
                param = strtok(NULL, " ");
                oparam = strtok(NULL, " ");

                if (oparam != NULL)
                {
                    oparam[strlen(oparam)-1] = '\0';
                    crtslf(param, oparam);
                }
                else
                    printf("Symbolic link name missing!\n");
            }
        }

        // implementacao da leitura de um link simbolico
        else if ((strcmp(command, "readslf") == 0) || (strcmp(command, "readslf\n") == 0))
        {
            if (strcmp(command, "readslf\n") == 0)
                printf("A symlink must be specified!\n");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';

                readslf(param);
            }
        }

        // implementacao da remocao de link simbolico
        else if ((strcmp(command, "rmslf") == 0) || (strcmp(command, "rmslf\n") == 0))
        {
            if (strcmp(command, "rmslf\n") == 0)
                printf("A linked file's name must be specified");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';

                rmslf(param);
            }
        }

        // prints help menu
        else if (strcmp(command, "help\n")  == 0) printhelp();
        
        // says goodbye and quits the shell
        else if (strcmp(command, "quit\n") == 0)
        {
            printf("Goodbye! o/\n\n");
            break;
        }

        else
            printf("Invalid command!\n\n");

	} while(1);

    return 0;
}

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
    {
        perror("Nem abriu kk");
    }
}

// creates a dir with the specified name
void crtdir(char *dirname)
{
    int status;
    status = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
    
    if (status != 0)
        printf("CRTDIR exit status: %d\n", status);
}

// changes to the specified dir
void chgdir(char *dirname)
{
    char *pwd;
    int extstat;
    
    getcwd(pwd, BUFFSIZE); // get full path to current dir
    
    /* concatenate destination directory */
    strcat(pwd, "/");
    strcat(pwd, dirname);
    strcat(pwd, "/");

    extstat = chdir(pwd);

    if (extstat != 0)
        printf("CHGDIR exit status: %d\n", extstat);
}

// creates a file in current dir
void crtfile(char *filename)
{
    int extstat;

    mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;

    extstat = creat(filename, mode);

    if (extstat == -1)
        printf("CRTFILE exit status: %d\n", extstat);

}

// removes a file in the current dir
void rmfile(char *filename)
{
    int extstat;

    extstat = remove(filename);
    
    if (extstat == -1)
        printf("RMFILE exit status: %d\n", extstat);
}

// creates a symbolic link to a file
void crtslf(char *oldname, char *newname)
{
    int extstat;

    extstat = symlink(oldname, newname);

    if (extstat != 0)
        printf("CRTSLF exit status: %d\n");
}

// reads the content of a symbolic link
void readslf(char *slname)
{
    char *buffer = NULL;
    int nchars;

    buffer = (char*) realloc(buffer, BUFFSIZE);
    nchars = readlink(slname, buffer, BUFFSIZE);

    strcat(slname, "\0");

    if (nchars < 0)
        free(buffer);
    else if (nchars <= BUFFSIZE)
        printf("%s\n", buffer);
}

// removes symbolic link to specified file
void rmslf(char *filename)
{
    int extstat;

    extstat = unlink(filename);

    if (extstat != 0)
        printf("RMSLF exit status: %d\n", extstat);
}

void printhelp()
{
    printf("crtdir - Create a directory\n"); // done
    printf("chgdir - Change to a directory\n"); // done
    printf("list - Lists contents of current directory\n"); // done
    printf("crtfile - Creates a file in the current directory\n"); // done
    printf("rmfile - Deletes a file in the current directory\n"); // done
    printf("crtslf - Creates symlink to file\n"); // done
    printf("rmslf - Removes symlink to file\n"); // 
    printf("readslf - Prints where the symlink is pointing to\n"); // done
    printf("35 - Shows contents of a file\n");
    printf("40 - Creates temporary text file\n");
    printf("help - Prints this somewhat useless text\n");
    printf("quit - Quit\n\n");
}