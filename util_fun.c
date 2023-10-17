#include "monty.h"

/**
 * stack_length - a function.
 * @stack: ptr to ptr stack.
 * Return: n.
 */

size_t stack_length(stack_t **stack)
{
	stack_t *curr;
	unsigned int n; /* counter for number of elements */

	curr = *stack;
	n = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		n++;
	}

	return (n);
}

/**
 * free_stack - a function.
 * @stack: ptr to ptr stack.
 * Return: void.
 */

void free_stack(stack_t **stack)
{
	stack_t *curr;

	while (*stack != NULL)
	{
		curr = *stack;
		*stack = (*stack)->next;
		free(curr);
	}
}

/**
 * free_all - a function.
 * @stack: ptr stack.
 * @line: ptr char.
 * @fp: ptr file.
 * Return: void.
 */

void free_all(stack_t *stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_stack(&stack);

	free(line);
	fclose(fp);
}
