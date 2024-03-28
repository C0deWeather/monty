#include "main.h"
#include <fcntl.h>

/**
 * main - entry point of program
 * @ac: argument count
 * @av: argumenent vector
 *
 * Return: 0 always
*/
int main(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	return (0);
}
