#include "shell.h"
/**
 * read_line - Read a line of input from stdin.
 *
 * If stdin is connected to a terminal, it displays a prompt and reads a line
 * of input from the user. Returns the input line as a dynamically allocated string.
 * If an error occurs or EOF is reached, returns NULL.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);/*allocate memory*/
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
