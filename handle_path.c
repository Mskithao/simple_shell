#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *find_command(char *command) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = custom_strtok(path_copy, ":");
    char *full_path = NULL;
    
    while (dir != NULL) {
        full_path = malloc(strlen(dir) + strlen(command) + 2); /*1 for '/' and 1 for null-terminator*/
        if (!full_path) {
            fprintf(stderr, "Allocation error\n");
            exit(EXIT_FAILURE);
        }
        
        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, command);
        
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        
        free(full_path);
        dir = custom_strtok(NULL, ":");
    }
    
    free(path_copy);
    return NULL; /*Command not found*/
}
