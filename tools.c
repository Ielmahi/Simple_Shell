#include "shell.h"

/**
 * freearray2D - Free memory allocated for a 2D array of strings.
 * @string_array: The 2D array of strings to be freed.
 */

void freearray2D(char **string_array)
{
    int index;

    if (!string_array)
        return;
    for (index = 0; string_array[index]; index++)
    {
        free(string_array[index]);
        string_array[index] = NULL;
    }
    free(string_array), string_array = NULL;
}

void printerror(char *program_name, char *command, int command_index)
{
    char *command_index_str, error_message[] = ": not found\n";

    command_index_str = _itoa(command_index);

    write(STDERR_FILENO, program_name, strlen(program_name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, command_index_str, strlen(command_index_str));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, command, strlen(command));
    write(STDERR_FILENO, error_message, strlen(error_message));
    free(command_index_str);
}

char *_itoa(int number)
{
    char buffer[20];
    int index = 0;

    if (number == 0)
        buffer[index++] = '0';
    else
    {
        while (number > 0)
        {
            buffer[index++] = (number % 10) + '0';
            number /= 10;
        }
    }
    buffer[index] = '\0';
    reverse_string(buffer, index);
    return (_strdup(buffer));
}

void reverse_string(char *str, int length)
{
    char tmp;
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}