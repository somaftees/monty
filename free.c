#include "monty.h"

/**
 * free_dlistint - free a list
 * @stack: pointer to head
 * Return: no return
 */
void free_dlistint(stack_t *stack)
{
	stack_t *stack_op = NULL;
	stack_t *stack_temp = NULL;

	stack_temp = stack;
	while (stack_temp != NULL)
	{
		stack_op = stack_temp->next;
		free(stack_temp);
		stack_temp = stack_op;
	}
	stack = NULL;
}

/**
 * free_globalvars - free list
 * Return: no return
 */
void free_globalvars(void)
{
	fclose(globalvar.fd);
	free(globalvar.line_buf);
}
