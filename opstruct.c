#include "monty.h"

/**
 * opcode_struct - a function.
 * @opcode: char.
 * @stack: ptr of ptr stack.
 * @line_number: unsigned int.
 * Return: 0 or 1.
 */
int opcode_struct(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pchar", pchar},
		{"pstr", pstr},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
