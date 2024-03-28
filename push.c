#include "monty.h"

/**
 * push - adds a new node to the stack
 * @head: the pointer to the head of the list
 * @line_number: line number
 *
 * Return: the address of the new element, or NULL if it failed.
*/
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;
	int n;

	if (isint(line[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		errno = EINVAL;
		return;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	n = atoi(line[1]);
	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

/**
 * isint - checks if input is an integer
 * @str: input string
 *
 * Return: 0 on success, and 1 on failure.
*/
int isint(char *str)
{
	if (str == NULL)
		return (1); /*Not an integer if the string is null*/

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
