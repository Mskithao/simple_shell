#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void builtin_env(void) {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}
