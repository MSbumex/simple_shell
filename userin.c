#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _userin - function to read user input
 * Return: return input or NULL
 */
char *_userin(void)
{
	static char _buff[BUFFER_SIZE];
	static size_t lengtbuf;
	static size_t pospoint;

	char *line = NULL;
	size_t line_length = 0;
	size_t newline_index = 0;
	size_t chunk_length, i;

	while (1)
	{
		if (pospoint >= lengtbuf)
		{
			lengtbuf = read(0, _buff, BUFFER_SIZE);
			if (lengtbuf == 0)
				break;
			if (lengtbuf == (size_t)-1)
				return (NULL);
			pospoint = 0;
		}

		newline_index = pospoint;
		while (newline_index < lengtbuf && _buff[newline_index] != '\n')
			newline_index++;
		chunk_length = newline_index - pospoint;
		line = realloc(line, (line_length + chunk_length + 1) * sizeof(char));
		if (line == NULL)
			return (NULL);
		for (i = 0; i < chunk_length; i++)
			line[line_length + i] = _buff[pospoint + i];
		line_length += chunk_length;
		pospoint = newline_index + 1;
		if (newline_index < lengtbuf && _buff[newline_index] == '\n')
		{
			line[line_length] = '\0';
			return (line);
		}
	}

	return (line);
}
