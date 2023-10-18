#include "project.h"
#include <string.h>

/**
 * str_toi - func to chang a str to int
 * @s: string
 * Return: return convert value  int
 */

int str_toi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
		{
			return (-1);
		}
		else if ((*s < '0' || *s > '9') && *s != '\0')
		{
			return (-1);
		}
		else if (*s >= '0'  && *s <= '9')
		{
			n = (n * 10) + (*s - '0');
		}
		else if (n > 0)
		{
			break;
		}
	} while (*s++);

	return (n);
}

/**
 * str_ch - func to get or find a char in str
 * @s:  string
 * @c: character
 * Return: return the c in s
 */

char *str_ch(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;

	if (s[i] == c)
	{
		return (s + i);
	}
	else
	{
		return (NULL);
	}
}

/**
 * str_seg - func for string segment
 * @s: string
 * @charset: charset to  used
 * Return: return index where char s exists in charset
 */

int str_seg(char *s, char *charset)
{
	int count = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (str_ch(charset, s[i]) != NULL)
		{
			break;
		}
		count++;
	}

	return (count);
}


/**
 * str_cmpr - func to compares str
 * @s: first string
 * @c: second string 
 *
 * Return: return 1 if match
 */

int str_cmpr(char *s, char *c)
{
	int i;

	for (i = 0; s[i] != '\0' && c[i] != '\0'; i++)
	{
		if (s[i] != c[i])
		{
			return (s[i] - c[i]);
		}
	}

	return (s[i] - c[i]);
}
