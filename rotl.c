#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: pointer to the head of the list
 * @line_number: line number
 */
void rotl(stack_t **head, unsigned int line_number)
{
	size_t len = stck_len(*head);
	stack_t *tmp = *head;
	stack_t *current = *head;

	if (len <= 1)
		return;
	else if (len == 2)
	{
		swap(head, line_number);
		return;
	}
	*head = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->prev = current;
	tmp->next = NULL;
	(*head)->prev = NULL;
}
/**
 * stck_len - returns the number of elements in a stack
 * @h: Pointer to the head of the list
 *
 * Return: the number of nodes
*/
size_t stck_len(stack_t *h)
{
	stack_t *current = h;
	size_t i = 0;

	while (current !=  NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
