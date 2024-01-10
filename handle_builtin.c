#include "shell.h"

/**
 * is_builtin - Check if a command is a built-in shell command.
 * @user_command: The command to be checked.
 *
 * Returns 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *user_command)
{
    char *builtin_commands[] = {
        "exit", "env", "setenv", 
        "cd", NULL
    };
    int i;

    for (i = 0; builtin_commands[i]; i++)
    {
        if (_strcmp(user_command, builtin_commands[i]) == 0)
            return (1);
    }
    return (0);
}

void handle_builtin(char **user_command, char **program_arguments, int *execution_status, int command_index)
{
    if (_strcmp(user_command[0], "exit") == 0)
        exit_shell(user_command, program_arguments, execution_status, command_index);
    else if (_strcmp(user_command[0], "env") == 0)
        print_environment(user_command, execution_status);
}

void exit_shell(char **user_command, char **program_arguments, int *execution_status, int command_index)
{
    int exit_value = (*execution_status);
    char *command_index_str, error_message[] = ": exit: Illegal number: ";

    if (user_command[1])
    {
        if (is_positive_number(user_command[1]))
        {
            exit_value = _atoi(user_command[1]);
        }
        else
        {
            command_index_str = _itoa(command_index);
            write(STDERR_FILENO, program_arguments[0], strlen(program_arguments[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, command_index_str, strlen(command_index_str));
            write(STDERR_FILENO, error_message, strlen(error_message));
            write(STDERR_FILENO, user_command[1], strlen(user_command[1]));
            write(STDERR_FILENO, "\n", 1);
            free(command_index_str);
            freearray2D(user_command);
            (*execution_status) = 2;
            return;
        }
    }
    freearray2D(user_command);
    exit(exit_value);
}

void print_environment(char **user_command, int *execution_status)
{
    int i;
    (void) execution_status;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearray2D(user_command);
    (*execution_status) = 0;
}
