#include "monty.h"

/**
 * pall - prints the value
 * @stack: pointer
 * @line_number: line
 * Return: void
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *c_stack = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (c_stack != NULL)
	{
		printf("%d\n", c_stack->n);
		c_stack = c_stack->next;
	}
}

/**
 * pint - prints value
 * @stack: pointer
 * @line_number: line
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n;
	printf("%d\n", result);
}

/**
 * pchar - prints the char
 * @stack: pointer
 * @line_number: line
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int variable_c;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	variable_c = (*stack)->n; /* head node's data */
	if (variable_c < 0 || variable_c > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(variable_c);
	putchar('\n');
}

/**
 * pstr - prints the string
 * @stack: pointer
 * @line_number: line
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int variable_c;
	stack_t *c_stack;
	(void)line_number;

	c_stack = *stack;
	while (c_stack != NULL)
	{
		variable_c = c_stack->n; /* c_stack node's data */
		if (variable_c > 0 && variable_c <= 127)
		{
			c_stack = c_stack->next;
			putchar(variable_c);
		}
		else
			break;
	}
	putchar('\n');
}
