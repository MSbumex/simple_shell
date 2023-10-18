#include "project.h"
#include <string.h>

/**
 * str_dup -  func to returns a duplicate string given as a parameter.
 * @str:  string
 * @dup:  duplicate string
 * Return: return duplicate string.
 */

char *str_dup(char *dup, char *str)
{
	int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * str_tok - func to split a str into  tokens
 * @str:  string
 * @delim:  delimiter
 * Return: return token or null
 */

char *str_tok(char *str, const char *delim)
{
	static char *saveptr;
	char *token;
	int i, j, len;

	if (str == NULL)
		str = saveptr;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	token = malloc(sizeof(char) * (len + 1));
	if (token == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				token[i] = '\0';
				saveptr = &str[i + 1];
				return (token);
			}
		}
		token[i] = str[i];
	}
	token[i] = '\0';
	saveptr = NULL;
	return (token);
}

/**
 * env_var - find shell environ list to get the var
 * @name: var name to search
 * Return: return value  pointer or null
 */

char *env_var(const char *name)
{
	int i, j, len;

	if (name == NULL)
		return (NULL);

	len = 0;
	while (name[len])
		len++;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}

	return (NULL);
}
