#include "monty.h"

/**
 * _div - divides the second top element of the stack by
 * the top element of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number
 */
void _div(stack_t **head, unsigned int line_number)
{
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		errno = EINVAL;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		errno = EINVAL;
		return;
	}
	result = ((*head)->next->n) / (*head)->n;
	pop(head, line_number);
	(*head)->n = result;
}
