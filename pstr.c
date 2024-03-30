#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @h: Pointer to the head of the list
 * @line_number: the current line number
 *
 * Return: the number of nodes
*/
void pstr(stack_t **h, unsigned int line_number)
{
	stack_t *current = *h;
	(void)line_number;

	while ((current !=  NULL) && (current->n > 0) && (current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
