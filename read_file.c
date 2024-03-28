#include <unistd.h>
#include "monty.h"

char **line = NULL;

/**
 * read_file - interprets monty code
 * @fd: file descriptor of an open file
*/
void read_file(int fd)
{
	char *buffer = NULL;
	unsigned int line_number = 1;
	stack_t *head = NULL;
	size_t n = 0;

	while (get_line(&buffer, &n, fd) != -1)
	{
		if (*buffer == '\0') /*Check for empty line*/
		{
			line_number++;
			free(buffer);
			continue;
		}
		line = parse_line(buffer);
		if (*line == NULL)
		{
			free(buffer);
			line_number++;
			free_line(line);
			continue;
		}
		free(buffer);
		exec(&head, line_number++);
		free_line(line);
	}
	free_stack(head);
}

/**
 * get_line - gets a line of text from an open stream
 * @buffer: pointer to buffer read line into
 * @n: size of buffer
 * @fd: file descriptor of input stream
 *
 * Return: on success returns the number of bytes read from the input stream,
 * otherwise, -1.
*/
ssize_t get_line(char **buffer, size_t *n, int fd)
{
	ssize_t bytes_read = 0, i;
	static  long int offset;
	char tmp[2048];

	lseek(fd, offset, SEEK_SET);

	bytes_read = read(fd, tmp, 2048);
	if (bytes_read <= 0)
		return (-1);
	for (i = 0; i < bytes_read; i++)
	{
		if (tmp[i] == '\n')
			break;
	}
	*buffer = malloc(i + 1);
	strncpy(*buffer, tmp, i);
	(*buffer)[i] = '\0';
	*n = i + 1;
	offset += i + 1;
	return (i);
}
