#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * tokey -func to seperate user's strings cmd
 * @receiv_user_in: get user input
 * @argv:  pointer to cmd char
 * @dis_input: gets the size of user input in bytes
 *
 * Return: array of pointer to strings
 */

char **tokey(char *receiv_user_in, char **argv, ssize_t dis_input)
{
	char *user_input_copy, *parse_token;
	const char *delimiter;
	int token_count = 0, num = 0;
	int token_length;

	delimiter = " \n";

	user_input_copy = malloc(sizeof(char) * (dis_input + 2));
	if (user_input_copy == NULL)
	{
		perror("Error: unable to allocate memory");
		return (NULL);
	}
	cp_str(user_input_copy, receiv_user_in);
	parse_token = str_tok(receiv_user_in, delimiter);

	while (parse_token != NULL)
	{
		token_count++;
		free(parse_token);
		parse_token = str_tok(NULL, delimiter);
	}
	token_count++;

	argv = malloc(sizeof(char *) * token_count);
	parse_token = str_tok(user_input_copy, delimiter);
	for (num = 0; parse_token != NULL; num++)
	{
		token_length = len_st(parse_token);
		argv[num] = malloc(sizeof(char) * token_length + 1);
		argv[num][token_length] = '\0';
		cp_str(argv[num], parse_token);
		free(parse_token);
		parse_token = str_tok(NULL, delimiter);
	}
	/*free(parse_token);*/
	argv[num] = NULL;
	free(user_input_copy);
	return (argv);

}
