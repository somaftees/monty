#include "monty.h"

/**
 * push - add
 * @stack: pointer
 * @line_number: line
 * @n: value
 * Return: void, exit with -1 on failure
 */
void push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new_stack = NULL;
	int counter;

	if (n == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (counter = 0; n[counter] != '\0'; counter++)
	{
		if (n[0] == '-' && counter == 0)
			continue;
		if (isdigit(n[counter]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_stack->n = atoi(n);
	new_stack->prev = NULL;
	new_stack->next = NULL;
	if (*stack != NULL)
	{
		new_stack->next = *stack;
		(*stack)->prev = new_stack;
	}

	*stack = new_stack;
}

/**
 * pop - remove item
 * @stack: pointer
 * @line_number: line
 * Return: void, exit with -1 on failure
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next_stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	next_stack = (*stack)->next; /* save next_stack node's address */
	free(*stack);
	*stack = next_stack; /* reassign next_stack node to head */
}

/**
 * swap - swaps the value of the top two elements on the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void, exit with -1 on failure
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int byte_a;
	int byte_b;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	byte_a = (*stack)->n;
	byte_b = (*stack)->next->n;

	(*stack)->n = byte_b;
	(*stack)->next->n = byte_a;
}

/**
 * nop - does nothing
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

