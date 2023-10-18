#include "monty.h"

/**
 * get_builtin - Parses the instruction
 * @token: type pointer
 * @stack: type pointer
 * @line_number: line
 * Return: Return the function
 */
int get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_types[] = {
		{ "push", push },
		{ "pall", pall},
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "mul", mul },
		{ "div", div_m },
		{ "pchar", pchar },
		{ "mod", mod_m },
		{ "\n", nop },
		{ " ", nop },
		{ "\t", nop },
		{ "pstr", pstr_t },
		{ "rotl", rotrl },
		{ "rotr", rotr },
		{ NULL, NULL }
	};
	int i, flag_count = 0;
	char *argument_type = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	argument_type = token;
	for (i = 0; op_types[i].opcode; i++)
	{
		if (strcmp(argument_type, op_types[i].opcode) == 0)
		{
			flag_count = 1;
			op_types[i].f(stack, line_number);
			break;
		}
	}
	if (flag_count == 0)
		stderr_unknown(token, line_number);
	return (0);
}
