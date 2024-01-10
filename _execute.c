#include "shell.h"
/**
 * _execute - Execute a command with its full path.
 * @command: Array of strings with the command and arguments.
 * @argv: Array of strings with program arguments.
 * @idx: Index of the command in the history.
 *
 * Attempts to execute the specified command using fork() and execve().
 * Waits for the child process to finish. Prints an error if the command
 * is not found.
 *
 * Returns the exit status of the executed command.
 */

int _execute(char **command,char **argv, int idx)
{
    char *full_cmd;
    pid_t child;
    int status;

    full_cmd = _getpath(command[0]);
    if (!full_cmd)
    {
        printerror(argv[0], command[0],  idx);
        freearray2D(command);
        return (127);
    }
    child = fork();
    if(child == 0)
    {
        if (execve(full_cmd, command, environ) == -1)
        {
            free(full_cmd), full_cmd = NULL;
            freearray2D(command);
        }
    }
    else
    {
        waitpid(child,&status,0);
        freearray2D(command);
        free(full_cmd), full_cmd = NULL;
    }
    return (WEXITSTATUS(status));
}
