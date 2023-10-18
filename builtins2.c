#include "monty.h"

/**
 * pop - Add
 * @stack: head
 * @line_number: line
 *
 * Return: No return
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_temp1 = NULL;
	stack_t *stack_temp2 = NULL;
	int i = 0, j = 0, flag_counter = 0;

	if (stack == NULL)
	{
		free_dlistint(*stack);
		pop_e(line_number); }
	if (*stack == NULL)
	{
		free_dlistint(*stack);
		pop_e(line_number); }
	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
		i++;
		flag_counter = 1;
	}
	stack_temp2 = *stack;
	while (j < (i - 1))
	{
		stack_temp2 = stack_temp2->next;
		j++;
	}
	if (i == 0 && flag_counter == 0)
	{

		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		stack_temp2->next = NULL;
		free(stack_temp1);
		stack_temp1 = NULL;
		return;
	}
}
/**
 * add - adds top
 * @stack: head
 * @line_number: line
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_temp1 = NULL;
	stack_t *stack_temp2 = NULL;
	int i = 0, j = 0, flag_counter = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "add");
	}
	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
		i++;
		flag_counter = 1;
	}
	stack_temp2 = *stack;
	while (j < (i - 1))
	{
		stack_temp2 = stack_temp2->next;
		j++;
	}
	if (i == 0 && flag_counter == 0)
		free_dlistint(*stack), op_e(line_number, "add");
	else
	{
		stack_temp2->n = stack_temp2->n + stack_temp1->n;
		stack_temp2->next = NULL;
		free(stack_temp1);
		stack_temp1 = NULL;
		return;
	}

}
/**
 * sub - subtracts the top
 * @stack: head
 * @line_number: line number
 */

void sub(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_temp1 = NULL;
	stack_t *stack_temp2 = NULL;
	int i = 0, j = 0, flag_counter = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "sub");
	}
	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
		i++;
		flag_counter = 1;
	}
	stack_temp2 = *stack;
	while (j < (i - 1))
	{
		stack_temp2 = stack_temp2->next;
		j++;
	}
	if (i == 0 && flag_counter == 0)
		free_dlistint(*stack), op_e(line_number, "sub");
	else
	{
		stack_temp2->n = stack_temp2->n - stack_temp1->n;
		stack_temp2->next = NULL;
		free(stack_temp1);
		stack_temp1 = NULL;
		return;
	}
}
/**
 * mul - Mul top of linkedlist
 * @stack: head
 * @line_number: line
 */
void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_temp1 = NULL;
	stack_t *stack_temp2 = NULL;
	int i = 0, j = 0, flag_counter = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "mul");
		return;
	}

	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
		i++;
		flag_counter = 1;
	}
	stack_temp2 = *stack;
	while (j < (i - 1))
	{
		stack_temp2 = stack_temp2->next;
		j++;
	}
	if (i == 0 && flag_counter == 0)
		free_dlistint(*stack), op_e(line_number, "mul");
	else
	{
		stack_temp2->n = stack_temp2->n * stack_temp1->n;
		stack_temp2->next = NULL;
		free(stack_temp1);
		stack_temp1 = NULL;
		return;
	}

}
/**
 * pchar - Print
 * @stack: head
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_temp1;

	if (*stack == NULL || stack == NULL)
	{
		pchar_e(line_number, "stack empty");
		return;
	}
	stack_temp1 = (*stack);
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
	}
	if (stack_temp1->n < 0 || stack_temp1->n > 127)
	{
		pchar_e(line_number, "value out of range");
	}
	printf("%c\n", stack_temp1->n);
}
