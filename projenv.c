#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_projenv - func to handle environ cmd
 * @user_input:  input (string)
 * @shell_data: structure of data
 */

void handle_projenv(char *user_input, data_shell *shell_data)
{
	free(user_input);
	shell_env(shell_data);
}

/**
 * shell_env - function to display shell environ
 * @shell_data: shell environment data
 * Return: returns 1 (if sucess)
 */
int shell_env(data_shell *shell_data)
{
	int i = 0;

	while (shell_data->_projenv[i])
	{
		int j = 0;

		while (shell_data->_projenv[i][j])
		{
			write(STDOUT_FILENO, &shell_data->_projenv[i][j], 1);
			j++;
		}

		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	shell_data->status_proces = 0;

	return (1);
}
