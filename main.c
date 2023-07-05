#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{   
    if (argc != 3)
    {
        printf("Usage clip <command> <text/file>\n");
        exit(EXIT_FAILURE);
    }
    FILE *db;
    char *to_be_copied = NULL;
    if (strcmp(argv[1], "copy") == 0)
    {
        db = fopen("clipboard.txt", "a+");
        to_be_copied = malloc(sizeof(char) * strlen(argv[2]) + 1);
        strncpy(to_be_copied, argv[2], strlen(argv[2]));
        to_be_copied[strlen(argv[2])] = '\0';
        printf("Copied to clipboard :%s\n", to_be_copied);
        fprintf(db, "%s\n", to_be_copied);
        fclose(db);
    }
    else if (strcmp(argv[1], "paste") == 0)
    {
        
        
        FILE *file_to_copied = fopen(strcat(strcat(getcwd(NULL,150),"/"),argv[2]), "a+");
        if (file_to_copied == NULL)
        {
            perror("File to Copied");
        }
        printf("%s\n",getcwd(NULL,150));
        db = fopen("clipboard.txt", "r");
        char *temp = malloc(sizeof(char) * 100);
        while ( fgets(temp, 99, db) != NULL )
            ;
        fclose(db);

        if (fwrite(temp, 1, strlen(temp), file_to_copied) <= 0)
        {
            printf("Return \n");
            exit(EXIT_FAILURE);
        }

        free(temp);
        fclose(file_to_copied);
    }



    free(to_be_copied);
    return 0;
}


