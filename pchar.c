#include "monty.h"

/**
 * pchar -  prints the char at the top of the stack
 * followed by a new line
 * @head: head of stack
 * @line_number: line number
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		errno = EINVAL;
		return;
	}
	if (((*head)->n >= 0) && (((*head)->n <= 127)))
	{
		printf("%c\n", (*head)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	errno = EINVAL;
}
