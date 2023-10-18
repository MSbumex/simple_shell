#include "project.h"

/**
 * promshel_rd - func reads shell prompts input
 * @dis_input:  number of size byt input read by userin
 * Return: return user input
 */

char *promshel_rd(ssize_t *dis_input)
{
	char *prompt = "MS&GOZO# ";
	char *user_input = NULL;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, 11);
	}

	user_input = _userin();
	if (user_input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	*dis_input = len_st(user_input);

	if (*dis_input == -1 && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	else if (*dis_input == -1)
	{
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	if (*dis_input == 0 && isatty(STDIN_FILENO))
	{
		free(user_input);
		return (promshel_rd(dis_input));
	}

	/*write(STDOUT_FILENO, user_input, byte_size for input);*/
	user_input[str_seg(user_input, "\n")] = '\0';
	return (user_input);
}
