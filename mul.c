#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number
 */
void mul(stack_t **head, unsigned int line_number)
{
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		errno = EINVAL;
		return;
	}
	result = ((*head)->n) * ((*head)->next->n);
	pop(head, line_number);
	(*head)->n = result;	
}
