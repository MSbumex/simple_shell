#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * terminate_shell- func to terminate shell
 * @_argv_receiv:  cmd receiv
 * @status_execute:  status of the terminate func
 * Return: nothing when terminate
 */

void terminate_shell(char **_argv_receiv, int status_execute)
{
	char **shell_cmd = NULL;
	/*int status = 0;*/
	int i = 0, arg;
	const char *error_msg = "Error: too many arguments\n";

	while (_argv_receiv[i] != NULL)
		i++;
	{

		if (i == 1)
		{
			free_array(_argv_receiv);
			free(shell_cmd);
			exit(status_execute);
		}
		else if (i == 2)
		{
			arg = str_toi(_argv_receiv[1]);
			if (arg < 0)
			{
				err_print(_argv_receiv, "Error: wrong input: ");
				err_str(_argv_receiv[1]);
				err_str("\n");
				/*status = 2;*/
			}
			else
			{
				free_array(_argv_receiv);
				free(shell_cmd);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_msg, strlen(error_msg));
	}
}
