#include "shell.h"
/**
 * is_positive_number - Check if a string represents a positive number.
 * @str: The input string to be checked.
 *
 * Returns 1 if the string represents a positive number, 0 otherwise.
 */

int is_positive_number(char *str)
{
    int  i;

    if (!str)
        return (0);
    for (i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int _atoi(char *str)
{
    int i , num = 0;

    for (i = 0; str[i]; i++)
    {
        num *= 10;
        num += (str[i] - '0');
    }
    return(num);
}
