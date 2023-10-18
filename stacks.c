#include "monty.h"

/**
 * create_node_stack - create
 * @stack: pointer
 * Return: EXIT SUCCESS
 */
int create_node_stack(stack_t **stack)
{
	stack_t *check_p;

	check_p = malloc(sizeof(stack_t));
	if (check_p == NULL)
		stderr_malloc();
	check_p->n = STACK;
	check_p->prev = NULL;
	check_p->next = NULL;

	*stack = check_p;

	return (EXIT_SUCCESS);
}
/**
 * free_node_stack - Frees
 * @stack: pointer
 */
void free_node_stack(stack_t **stack)
{
	stack_t *tempstack_node = *stack;

	while (*stack)
	{
		tempstack_node = (*stack)->next;
		free(*stack);
		*stack = tempstack_node;
	}
}
/**
 * check_opcode - check function
 * @stack: pointer
 * Return: The value
 */
int check_opcode(stack_t *stack)
{
	int result = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (result);
}
