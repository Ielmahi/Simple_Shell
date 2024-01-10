#include "shell.h"
/**
 * tokenizer - Tokenize a string into an array of strings.
 * @line: The string to be tokenized.
 *
 * This function takes a string and tokenizes it using the specified delimiter.
 * It returns an array of strings, where each element represents a token.
 * The last element of the array is set to NULL.
 *
 * @return: Array of strings representing tokens or NULL on failure.
 */

char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);
        while (token)
        {
                command[i++] = _strdup(token);
                token = strtok(NULL, DELIM);
        }
	free(line);/*line == NULL;*/
	command[i] = NULL;
	return (command);

}
