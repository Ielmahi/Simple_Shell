#include "shell.h"
/*
 * main - Simple Shell main function
 * @ac : Count of argument
 * @av : Arguments
 * Return : 0 Always (success)
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		line = read_line();
		if (line == NULL) /* reache EOF ctr + D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		command = tokenizer(line);
		if (!command)
			continue;
		if (is_builtin(command[0]))
			handle_builtin(command, av, &status, idx);
		else
			status = _execute(command, av, idx);
	}
}
