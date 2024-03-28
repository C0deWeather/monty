#include "main.h"

/**
 * free_line - frees an array of strings
 * @line: the arrayi of strings
 */
void free_line(char **line)
{
	int i;

	for (i = 0; line[i] != NULL; i++)
		free(line[i]);
	free(line);
}

/**
 * free_stack - frees a stack
 * @head: the pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *previous = NULL;

	while (head != NULL && head->next != NULL)
	{
		previous = head;
		head = head->next;
		free(previous);
	}
	free(head);
}
