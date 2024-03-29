#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: the head of the stack
 * @line_number: line number
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
 
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		errno = EINVAL;
		return;
	}
	*head = current->next;
	if (current->next)
		current->next->prev = NULL;
	free(current);
}
