#include "monty.h"

/**
 * _add - adds top two
 * @stack: pointer
 * @line_number: line number
 * Return: void, exit with -1 on failure
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int var_a;
	int var_b;
	int add_result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	var_a = (*stack)->n;
	var_b = (*stack)->next->n;

	add_result = var_a + var_b;

	pop(stack, line_number);

	(*stack)->n = add_result;
}

/**
 * _sub - subtracts top
 * @stack: pointer
 * @line_number: line
 * Return: void, exit with -1 on failure
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int var_a;
	int var_b;
	int add_result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	var_a = (*stack)->n;
	var_b = (*stack)->next->n;

	add_result = var_b - var_a;

	pop(stack, line_number);

	(*stack)->n = add_result;
}

/**
 * _mul - multiplies top
 * @stack: pointer
 * @line_number: line
 * Return: void, exit with -1 on failure
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int var_a;
	int var_b;
	int add_result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	var_a = (*stack)->n;
	var_b = (*stack)->next->n;

	add_result = var_a * var_b;

	pop(stack, line_number);

	(*stack)->n = add_result;
}

/**
 * _div - divides top
 * @stack: pointer
 * @line_number: line
 * Return: void, exit with -1 on failure
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int var_a;
	int var_b;
	int add_result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	var_a = (*stack)->n;
	var_b = (*stack)->next->n;
	if (var_a == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_result = var_b / var_a;

	pop(stack, line_number);

	(*stack)->n = add_result;
}

/**
 * _mod - divides top
 * @stack: pointer
 * @line_number: line
 * Return: void, exit with -1 on failure
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int var_a;
	int var_b;
	int add_result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	var_a = (*stack)->n;
	var_b = (*stack)->next->n;
	if (var_a == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	add_result = var_b % var_a;

	pop(stack, line_number);

	(*stack)->n = result;
}
