#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char **split_arguments(char *line) {
    int bufsize = 64; /*Initial buffer size*/
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;
    
    if (!tokens) {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    token = custom_strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;
        
        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = custom_strtok(NULL, " \t\r\n\a");
    }
    
    tokens[position] = NULL;
    return tokens;
}
