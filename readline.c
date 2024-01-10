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
    char *user_input = NULL;
    size_t input_length = 0;
    ssize_t characters_read;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    characters_read = getline(&user_input, &input_length, stdin);/*allocate memory*/
    if (characters_read == -1)
    {
        free(user_input);
        return (NULL);
    }
    return (user_input);
}
