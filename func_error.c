#include "project.h"
#include <string.h>

/**
 * err_str - func to print str error
 * @str: string
 * Return: return value
 */

int err_str(char *str)
{
	int i;

	if (!(str))
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		write(2, &str[i], 1);
	}

	return (i);
}

/**
 * err_print - func to print an error msg
 * @av: argument
 * @err: error msg
 */

void err_print(char **av, char *err)
{
	err_str(env_var("_"));
	err_str(": 1: ");
	err_str(av[0]);
	err_str(": ");
	err_str(err);
}
