#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int main(int argc, char *argv[]) {
    char *line;
    
    while (1) {
        printf("$ ");
        line = custom_getline(); /*Read input line*/
        
        if (line == NULL) {
            break; /*Exit loop on EOF (Ctrl+D)*/
        }
        
        remove_comments(line); /*Remove comments from input*/
        
        if (line[0] != '\0') {
            handle_semicolon(line); /*Execute commands separated by semicolons*/
        }
        
        free(line);
    }
    
    printf("\n"); /*Print newline before exiting*/
    return 0;
}
