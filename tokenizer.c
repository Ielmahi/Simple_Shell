#include "shell.h"

/**
 * tokenizer - Tokenize a string into an array of strings.
 * @input_string: The string to be tokenized.
 *
 * This function takes a string and tokenizes it using the specified delimiter.
 * It returns an array of strings, where each element represents a token.
 * The last element of the array is set to NULL.
 *
 * @return: Array of strings representing tokens or NULL on failure.
 */
char **tokenizer(char *input_string)
{
    char *token = NULL, *temporary_string = NULL;
    char **token_array = NULL;
    int token_count = 0, index = 0;

    if (!input_string)
        return (NULL);
    temporary_string = _strdup(input_string);
    token = strtok(temporary_string, DELIM);
    if (token == NULL)
    {
        free(temporary_string);
        free(input_string);
        return (NULL);
    }
    while (token)
    {
        token_count++;
        token = strtok(NULL, DELIM);
    }
    free(temporary_string), temporary_string = NULL;

    token_array = malloc(sizeof(char *) * (token_count + 1));
    if (!token_array)
    {
        free(input_string);
        return (NULL);
    }

    token = strtok(input_string, DELIM);
    while (token)
    {
        token_array[index++] = _strdup(token);
        token = strtok(NULL, DELIM);
    }
    free(input_string);/*input_string == NULL;*/
    token_array[index] = NULL;
    return (token_array);
}
