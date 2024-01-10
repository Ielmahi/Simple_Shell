#include "shell.h"

/**
 * is_positive_number - Check if a string represents a positive number.
 * @number_str: The input string to be checked.
 *
 * Returns 1 if the string represents a positive number, 0 otherwise.
 */
int is_positive_number(char *number_str)
{
    int  index;

    if (!number_str)
        return (0);
    for (index = 0; number_str[index]; index++)
    {
        if (number_str[index] < '0' || number_str[index] > '9')
            return (0);
    }
    return (1);
}

int _atoi(char *number_str)
{
    int index, result = 0;

    for (index = 0; number_str[index]; index++)
    {
        result *= 10;
        result += (number_str[index] - '0');
    }
    return(result);
}
