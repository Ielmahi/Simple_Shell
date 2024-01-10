#include "shell.h"

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