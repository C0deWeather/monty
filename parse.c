#include "monty.h"

/**
 * *_strdup - duplicates input string
 * @str: input string
 *
 * Return: pointer to a dynamically allocated
 * memory containing the duplicate string.
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int size;

	if (str == NULL)
		return (NULL);
	size = strlen(str) + 1;
	/*Allocate dynamic meemory to array*/
	s = (char *)malloc(size);

	/*Condition for unsuccessful allocation*/
	if (s == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	/*Copy contents of str into s*/
	return (strcpy(s, str));
}

/**
 * parse_line - split input string into tokens
 * @buffer: input string
 *
 * Return: returns a pointer to a dynamically allocated
 * array of tokens, otherwise NULL.
*/
char **parse_line(char *buffer)
{
	int i = 0, count;
	char *tmp_tok, *tmp_buff = _strdup(buffer);
	char **tokens;
	char delimiter[] = " ";

	if (tmp_buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	/*count tokens*/
	tmp_tok = strtok(tmp_buff, delimiter);
	for (count = 1; tmp_tok != NULL; count++)
		tmp_tok = strtok(NULL, delimiter);

	/*tokenize line*/
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	tokens[i] = _strdup(strtok(buffer, delimiter));
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = _strdup(strtok(NULL, delimiter));
	}
	free(tmp_buff);
	return (tokens);
}
