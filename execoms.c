#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/**
 * execmd - function to execute user cmd
 * @_argv_receiv: an array to the pointer of strings
 * Return: no value
 */
int execmd(char **_argv_receiv)
{
	char *init_cmd, *last_cmd;
	pid_t child_process;
	int status_proces = 0;

	init_cmd = NULL;
	last_cmd = NULL;
	child_process = -1;
	init_cmd = _argv_receiv[0];
	last_cmd = _pathget(init_cmd);

	if (last_cmd == NULL)
		return (1);
	if (_argv_receiv && access(last_cmd, X_OK) != -1)
	{
		child_process = fork();

		if (child_process == -1)
		{
			err_print(_argv_receiv, "Error: command not found\n");
		}
		else if (child_process == 0)
		{

			if (execve(last_cmd, _argv_receiv, NULL) == -1)
				err_print(_argv_receiv, "Error: command not found\n");

		}
		else
		{
			if (waitpid(child_process, &status_proces, 0) == -1)
				err_print(_argv_receiv, "Error: command not found\n");
		}
		if (str_cmpr(last_cmd, init_cmd) != 0)
			free(last_cmd);
		if (WIFEXITED(status_proces))
			status_proces = WEXITSTATUS(status_proces);
		return (status_proces);
	}
	free(last_cmd);
	return (1);
}
