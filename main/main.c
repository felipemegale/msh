#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sl/sl.h"
#include "../help/help.h"
#include "../files/files.h"
#include "../dirs/dirs.h"

#define BUFFSIZE 120

int main()
{
    char *input = (char*) calloc (BUFFSIZE, sizeof(char));
    char *command, *param, *oparam;
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

        // implementacao da impressao do conteudo de um arquivo na tela
        else if ((strcmp(command, "shwfctt") == 0) || (strcmp(command, "shwfctt\n") == 0))
        {
            if ((strcmp(command, "shwfctt\n") == 0))
                printf("A file name must be specified!\n");
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';

                shwfctt(param);
            }
        }

        // implementacao da criacao de arquivos temporarios
        else if ((strcmp(command, "crttmpf") == 0) || (strcmp(command, "crttmpf\n") == 0))
        {
            if (strcmp(command, "crttmpf\n") == 0)
                crttmpf(NULL);
            else
            {
                param = strtok(NULL, " ");
                param[strlen(param)-1] = '\0';

                if (strlen(param) >= BUFFSIZE)
                    printf("Max of %d characters only.\n", BUFFSIZE);
                else
                    crttmpf(param);
            }
        }

        // mostra quem fez isso
        else if (strcmp(command, "whoisresponsibleforthis\n") == 0)
            printf("Felipe Marques Megale - 476280\nGuilherme Galvao 552135\n\n");

        else if(strcmp(command, "whatisyawcs\n") == 0)
            printf("Yet Another Wannabe Computer Scientist\n");

        // prints help menu
        else if (strcmp(command, "help\n")  == 0) printhelp();
        
        // says goodbye and quits the shell
        else if (strcmp(command, "exit\n") == 0)
        {
            printf("Goodbye! o/\n\n");
            break;
        }

        else
            printf("Invalid command!\n\n");

	} while(1);

    return 0;
}