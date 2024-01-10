#include "shell.h"

/**
 * _getpath - Retrieve the full path of a command from the PATH environment variable.
 * @user_command: The command to find in the PATH.
 *
 * This function takes a command and checks if it contains a '/' character. If it
 * does, it checks if the command exists, and if so, returns a duplicated string
 * with the full path. If the command doesn't contain '/', it searches through the
 * directories listed in the PATH environment variable to find the full path.
 *
 * @return: The full path of the command or NULL if not found.
 */
char *_getpath(char *user_command)
{
    char *path_environment, *full_path, *directory;
    int index;
    struct stat file_status;

    for (index = 0; user_command[index]; index++)
    {
        if (user_command[index] == '/')
        {
            if (stat(user_command, &file_status) == 0)
                return (_strdup(user_command));
            return (NULL);
        }
    }
    path_environment = _getenv("PATH");
    if (!path_environment)
        return (NULL);
    directory = strtok(path_environment, ":");
    while (directory)
    {
        full_path = malloc(strlen(directory) + strlen(user_command) + 2);
        if (full_path)
        {
            _strcpy(full_path, directory);
            _strcat(full_path, "/");
            _strcat(full_path, user_command);
            if (stat(full_path, &file_status) == 0)
            {
                free(path_environment);
                return (full_path);
            }
            free(full_path), full_path = NULL;
            directory = strtok(NULL, ":");
        }
    }
    free(path_environment);
    return(NULL);
}
