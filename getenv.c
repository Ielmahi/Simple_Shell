#include "shell.h"
/**
 * _getenv - Retrieve the value of an environment variable.
 * @variable: The name of the environment variable to retrieve.
 *
 * This function searches through the environment variables and returns
 * the value associated with the specified variable name. If the variable
 * is not found, it returns NULL.
 *
 * @return: The value of the environment variable or NULL if not found.
 */

char *_getenv(char *variable)
{
	int i;
	char *tmp,*key,*value, *env;

	for(i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if(_strcmp(key,variable) == 0)
		{
			value = strtok(NULL,"\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp),tmp = NULL;
	}
	return (NULL);
}
