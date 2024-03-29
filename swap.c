#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head:  pointer to the head of the stack
 * @line_number: line number
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		errno = EINVAL;
		return;
	}
	*head = tmp->next; /*move head to next node*/
	tmp->prev = *head;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	(*head)->prev = NULL;
}
