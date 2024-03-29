#include "monty.h"

/**
 * pint -  prints the value at the top of the stack
 * @head: head of stack
 * @line_number: line number
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		errno = EINVAL;
		return;
	}
	printf("%d\n", (*head)->n);
}
