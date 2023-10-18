#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * _pathget - func to get path of cmd
 * @init_cmd:  input cmd
 *
 * Return: return cmd path
 */

char *_pathget(char *init_cmd)
{
	struct stat path_test;
	char *cmd_path, *cmd_path_copy = NULL, *delimiter;
	char *path_to_file, *parse_token;
	int dir_len, user_length_cmd, path_to_file_len, i;

	delimiter = ":";
	cmd_path = env_var("PATH");

	if (stat(init_cmd, &path_test) == 0)
		return (init_cmd);

	if (cmd_path)
	{	cmd_path_copy = str_dup(cmd_path_copy, cmd_path);
		user_length_cmd = len_st(init_cmd);
		parse_token = str_tok(cmd_path_copy, delimiter);

		while (parse_token != NULL)
		{
			dir_len = len_st(parse_token);
			path_to_file_len = user_length_cmd + dir_len + 2;
			path_to_file = malloc(path_to_file_len);
			path_to_file[0] = '\0';
			for (i = 0; i < path_to_file_len; i++)
				path_to_file[i] = '\0';
			cp_str(path_to_file, parse_token);
			concat_str(path_to_file, "/");
			concat_str(path_to_file, init_cmd);
			concat_str(path_to_file, "\0");
			if (stat(path_to_file, &path_test) == 0)
			{	free(cmd_path_copy);
				free(parse_token);
				return (path_to_file);
			}
			free(path_to_file);
			free(parse_token);
			parse_token = str_tok(NULL, delimiter);
		}
	}
	free(cmd_path_copy);
	return (NULL);
}
