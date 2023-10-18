#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/**
 * unenvicon_shell -func to delete an shell variable
 * @args: array of pointer
 *
 * Return: 0 if  success, -1 if fail
 */

int unenvicon_shell(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (-1);
	}

	if (getenv(args[1]) == NULL)
	{
		return (0);
	}
	unsetenv(args[1]);

	return (0);
}

/**
 * envi_command - func to  handle setenv, unsetenv, echo cmd
 * @args: array pointer argument
 *
 * Return: 1 if success, 0 if not
 */

int envi_command(char **args)
{
	char *value;

	if (str_cmpr(args[0], "envicon") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
			return (-1);
		if (envicon_shell(args) == -1)
			err_print(args, "Error: unable to set environment variable\n");
		return (1);
	}
	else if (str_cmpr(args[0], "envicon") == 0)
	{
		if (args[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: unenvicon VARIABLE\n", 26);
			return (-1);
		}
		if (unsetenv(args[1]) == -1)
		{	write(STDERR_FILENO, "Unable to unset environment variable\n", 37);
			return (-1);
		}
		unenvicon_shell(args);
		return (1);
	}
	else if (str_cmpr(args[0], "echo") == 0)
	{
		if (args[1] == NULL)
		{	write(STDERR_FILENO, "Usage: echo VARIABLE\n", 21);
			return (-1);
		}
		value = getenv(args[1]);
		if (value != NULL)
		{	write(STDOUT_FILENO, value, len_st(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDOUT_FILENO, "$\n", 2);
		return (1);
	}
	return (0);
}

/**
 * envicon_shell - func to give new shell variable or modify
 * @args: an array of arg
 * Return: 0 if success, -1 if not
 */

int envicon_shell(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE\n", 29);
		return (-1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		err_print(args, "Failed to set environment variable\n");
		return (-1);
	}

	return (0);
}
