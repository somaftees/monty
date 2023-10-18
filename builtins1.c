#include "monty.h"

/**
 * push - Add node
 * @stack: head
 * @line_number: line number of the instruction
 * Return: No return
 */

void push(stack_t **stack, unsigned int line_number)
{

	int num = 0;

	if (globalvar.token2 == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	num = atoi(globalvar.token2);
	if (*stack  == NULL)
	{
		create_node_stackfirst(stack, num);
	}
	else
	{
		create_node_stackend(stack, num);
	}
}

/**
 * pall - Print
 * @stack: head
 * @line_number: line
 * Return: No return
 */
void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_val = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		free_dlistint(*stack);
		free_globalvars();
		exit(EXIT_SUCCESS);
	}
	stack_val = *stack;
	while (stack_val->next != NULL)
		stack_val = stack_val->next;
	while (stack_val->prev != NULL)
	{
		printf("%d", stack_val->n);
		stack_val = stack_val->prev;
		printf("\n");
	}
	printf("%d\n", stack_val->n);
}


/**
 * pint - Print
 * @stack: head
 * @line_number: line number
 * Return: No return
 */
void pint(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_val = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_e(line_number);
		return;
	}
	stack_val = *stack;
	while (stack_val->next != NULL)
		stack_val = stack_val->next;

	printf("%d", stack_val->n);
	printf("\n");
}

/**
 * swap - Print
 * @stack: head
 * @line_number: line number
 * Return: No return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_val;
	int i, j;

	if (*stack == NULL || stack == NULL)
		op_e(line_number, "swap");

	stack_val = (*stack)->next;
	if ((*stack)->next == NULL)
		op_e(line_number, "swap");
	while (stack_val->next != NULL)
	{
		stack_val = stack_val->next;
	}
	i = stack_val->n;
	j = stack_val->prev->n;
	stack_val->n = j;
	stack_val->prev->n = i;
}
/**
 * nop - does
 * @stack: head
 * @line_number: line number
 *
 * Return: No return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
