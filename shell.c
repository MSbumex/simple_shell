#include "project.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - entry point of shell enviro
 * @arg_c: arg count
 * @argv: pointer to argument strings
 * Return: 0 or 1
 */

int main(int arg_c, char **argv)
{
	char *user_input, **_argv_receiv;
	ssize_t dis_input;
	int i, status_execute = 0;
	data_shell shell_data;

	shell_data._projenv = environ;
	(void)arg_c;
	(void)argv;

	while (1 == 1)
	{
		user_input = NULL, dis_input = 0;
		user_input = promshel_rd(&dis_input);
		_argv_receiv = tokey(user_input, _argv_receiv, dis_input);
		if (_argv_receiv[0] == NULL)
			continue;
		if (str_cmpr(_argv_receiv[0], "env") == 0)
		{	free(user_input);
			shell_env(&shell_data);
			free_array(_argv_receiv);
			continue;	}
		if (str_cmpr(_argv_receiv[0], "exit") == 0)
		{	free(user_input);
			terminate_shell(_argv_receiv, status_execute);
			free_array(_argv_receiv);
			continue;
		}
		i = envi_command(_argv_receiv);
		if (i != 0)
		{	free(user_input);
			free_array(_argv_receiv);
			continue;
		}
		status_execute = execmd(_argv_receiv);
		if (status_execute == 1)
			err_print(_argv_receiv, "Error: not found\n");
		free(user_input);
		free_array(_argv_receiv);
	}
	return (0);
}
