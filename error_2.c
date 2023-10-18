#include "monty.h"

/**
 * pop_e - pop error
 * @line_number: line
 * Return: EXIT_FAILURE.
 */
void pop_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * pint_e - pint error
 * @line_number: line
 * Return: EXIT_FAILURE
 */
void pint_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * op_e - math
 * @line_number: line
 * @op: Operation
 * Return: EXIT_FAILURE
 */
void op_e(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	free_globalvars();
	exit(EXIT_FAILURE);
}
/**
 * pchar_e - phar error
 * @line_number: line number
 * @msg: error message
 * Return: EXIT_FAILURE.
 */
void pchar_e(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * div_e - error
 * @line_number: line
 * Return: EXIT_FAILURE
 */
void div_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}
