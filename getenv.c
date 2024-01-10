#include "shell.h"

/**
 * _getenv - Retrieve the value of an environment variable.
 * @search_var: The name of the environment variable to retrieve.
 *
 * This function searches through the environment variables and returns
 * the value associated with the specified variable name. If the variable
 * is not found, it returns NULL.
 *
 * @return: The value of the environment variable or NULL if not found.
 */
char *_getenv(char *search_var)
{
    int index;
    char *temp, *key, *value, *result;

    for(index = 0; environ[index]; index++)
    {
        temp = _strdup(environ[index]);
        key = strtok(temp, "=");
        if(_strcmp(key, search_var) == 0)
        {
            value = strtok(NULL,"\n");
            result = _strdup(value);
            free(temp);
            return (result);
        }
        free(temp), temp = NULL;
    }
    return (NULL);
}
