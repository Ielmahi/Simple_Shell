#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>

#define DELIM " \t\n"
extern char **environ;
char *read_line(void);
char **tokenizer(char *line);
int _execute(char **command,char **argv, int idx);
void freearray2D(char **array);
char *_getenv(char *variable);
char *_getpath(char *command);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);
void print_env(char **command, int *status);
void exit_shell(char **command, char **argv, int *status, int idx);
void handle_builtin(char **command, char **argv, int *status, int idx);
int is_builtin(char *command);
int _atoi(char *str);
int is_positive_number(char *str);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
