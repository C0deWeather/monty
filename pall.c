#include "main.h"

/**
 * pall - prints all the elements of a stack
 * @h: Pointer to the head of the list
 * @line_number: the current line number
 *
 * Return: the number of nodes
*/
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *current = *h;
	(void)line_number;

	while (current !=  NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
