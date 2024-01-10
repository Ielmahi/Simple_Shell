#include "shell.h"
/**
 * _getpath - Retrieve the full path of a command from the PATH environment variable.
 * @command: The command to find in the PATH.
 *
 * This function takes a command and checks if it contains a '/' character. If it
 * does, it checks if the command exists, and if so, returns a duplicated string
 * with the full path. If the command doesn't contain '/', it searches through the
 * directories listed in the PATH environment variable to find the full path.
 *
 * @return: The full path of the command or NULL if not found.
 */

char *_getpath(char *command)
{
    char *path_env, *full_cmd, *dir;
    int i;
    struct stat st;

    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return (_strdup(command));
            return (NULL);
        }
    }
    path_env = _getenv("PATH");
    if (!path_env)
        return (NULL);
    dir = strtok(path_env, ":");
    while (dir)
    {
        full_cmd = malloc(strlen(dir) + strlen(command) + 2);
        if (full_cmd)
        {
            _strcpy(full_cmd, dir);
            _strcat(full_cmd, "/");
            _strcat(full_cmd, command);
            if (stat(full_cmd, &st) == 0)
            {
                free(path_env);
                return (full_cmd);
            }
            free(full_cmd), full_cmd = NULL;
            dir = strtok(NULL, ":");
        }
    }
    free(path_env);
    return(NULL);
}
