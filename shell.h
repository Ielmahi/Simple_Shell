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
char **tokenizer(char *input_string);
int _execute(char **cmd_args, char **program_args, int history_idx);
void freearray2D(char **string_array);
char *_getenv(char *search_var);
char *_getpath(char *user_command);
void printerror(char *program_name, char *command, int command_index);
char *_itoa(int number);
void reverse_string(char *str, int length);
void print_environment(char **user_command, int *execution_status);
void exit_shell(char **command, char **argv, int *status, int idx);
void handle_builtin(char **user_command, char **program_arguments, int *execution_status, int command_index);
int is_builtin(char *user_command);
int _atoi(char *number_str);
int is_positive_number(char *number_str);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
