#include "shell.h"

/**
 * _execute - Execute a command with its full path.
 * @cmd_args: Array of strings with the command and arguments.
 * @program_args: Array of strings with program arguments.
 * @history_idx: Index of the command in the history.
 *
 * Attempts to execute the specified command using fork() and execve().
 * Waits for the child process to finish. Prints an error if the command
 * is not found.
 *
 * Returns the exit status of the executed command.
 */
int _execute(char **cmd_args, char **program_args, int history_idx)
{
    char *full_path;
    pid_t child_pid;
    int child_status;

    full_path = _getpath(cmd_args[0]);
    if (!full_path)
    {
        printerror(program_args[0], cmd_args[0],  history_idx);
        freearray2D(cmd_args);
        return (127);
    }

    child_pid = fork();
    if (child_pid == 0)
    {
        if (execve(full_path, cmd_args, environ) == -1)
        {
            free(full_path), full_path = NULL;
            freearray2D(cmd_args);
        }
    }
    else
    {
        waitpid(child_pid, &child_status, 0);
        freearray2D(cmd_args);
        free(full_path), full_path = NULL;
    }

    return (WEXITSTATUS(child_status));
}
