#include "project.h"


/**
 * len_st - func to count lengt of str
 * @string: strin
 * Return: return value
 */

int len_st(char *string)
{
	int i;
	int num;

	num = 0;

	for (i = 0; string[i] != '\0'; i++)
		num++;

	return (num);
}


/**
 * cp_str - func to copy str
 * @to: string to
 * @from: string from
 *
 * Return: no return or void
 */

void cp_str(char *to, char *from)
{
	int i;

	for (i = 0; from[i] != '\0'; i++)
		to[i] = from[i];

	to[i] = '\0';
}


/**
 * concat_str - func to concat  str
 * @text_add: adding text
 * @text: text from
 *
 * Return: no return
 */
void concat_str(char *text_add, char *text)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (text_add[i] != '\0')
		i++;
	for (num = 0; text[num] != '\0'; num++)
		text_add[i++] = text[num];
	text_add[i] = '\0';
}


/**
 * free_array - func to free  allocated str arr of arg
 * @argv: array of strings 
 *
 */
void free_array(char **argv)
{
	char **temp = argv;

	for (; *temp != NULL; temp++)
	{
		free(*temp);
		*temp = NULL;
	}
	free(argv);
}

