#include "monty.h"

/**
 * exec - executes a command
 * @line_number: current line number
 * @head: pointer to head of stack
*/
void exec(stack_t **head, unsigned int line_number)
{
	unsigned int i;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"div", _div},
		{"sub", sub},
		{"mod", mod},
		{"mul", mul},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL},
	};

	for (i = 0; instruction[i].opcode != NULL; i++)
	{
		if (!(strcmp(line[0], instruction[i].opcode)))
		{
			instruction[i].f(head, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, line[0]);
	errno = EINVAL;
}
