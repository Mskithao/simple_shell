#ifndef SHELL_H
#define SHELL_H

char *custom_getline(void);
char *custom_strtok(char *str, const char *delim);
void handle_semicolon(char *line);
void remove_comments(char *line);

#endif /* SHELL_H */

