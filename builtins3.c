#include "monty.h"

/**
 * div_m - divs numbers
 * @stack: head
 * @line_number: line number
 */

void div_m(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_temp1 = NULL;
	stack_t *satck_temp2 = NULL;
	int i = 0, j = 0, flag_count = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "div");
	}

	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
		i++;
		flag_count = 1;
	}
	satck_temp2 = *stack;
	while (j < (i - 1))
	{
		satck_temp2 = satck_temp2->next;
		j++;
	}
	if (i == 0 && flag_count == 0)
		free_dlistint(*stack), op_e(line_number, "div");
	else
	{
		if (stack_temp1->n == 0)
			div_e(line_number);
		satck_temp2->n = satck_temp2->n / stack_temp1->n;
		satck_temp2->next = NULL;
		free(stack_temp1);
		stack_temp1 = NULL;
		return;
	}



}
/**
 * mod_m - mod top
 * @stack: head
 * @line_number: line
 */
void mod_m(stack_t **stack, unsigned int line_number)
{

	stack_t *stack_temp1 = NULL;
	stack_t *satck_temp2 = NULL;
	int i = 0, j = 0, flag_count = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "mod");
	}

	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
	{
		stack_temp1 = stack_temp1->next;
		i++;
		flag_count = 1;
	}
	satck_temp2 = *stack;
	while (j < (i - 1))
	{
		satck_temp2 = satck_temp2->next;
		j++;
	}
	if (i == 0 && flag_count == 0)
		free_dlistint(*stack), op_e(line_number, "mod");
	else
	{
		if (stack_temp1->n == 0)
			div_e(line_number);
		satck_temp2->n = satck_temp2->n % stack_temp1->n;
		satck_temp2->next = NULL;
		free(stack_temp1);
		stack_temp1 = NULL;
		return;
	}
}

/**
 * pstr_t - prints
 * @stack: head
 * @line_number: line number
 */
void pstr_t(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_temp1 = NULL;
	(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		free_globalvars();
		exit(0);
	}
	stack_temp1 = *stack;
	if (stack_temp1->next == NULL && line_number == 2 && (stack_temp1->n < 0 || stack_temp1->n >= 127))
	{
		printf("\n");
		free_dlistint(*stack);
		free_globalvars();
		exit(0);
	}
	while (stack_temp1->next != NULL)
		stack_temp1 = stack_temp1->next;
	while (stack_temp1->prev != NULL)
	{
		if (stack_temp1->n > 0 && stack_temp1->n < 127)
		{
			printf("%c", stack_temp1->n);
			stack_temp1 = stack_temp1->prev;
		}
		else
			stack_temp1 = stack_temp1->prev;
		if (stack_temp1->n <= 0 || stack_temp1->n >= 127)
		{
			printf("\n");
			return;
		}
	}
	printf("%c\n", stack_temp1->n);
}
/**
 * rotrl - rotate
 * @stack: head
 * @line_number: line number
 */
void rotrl(stack_t **stack, unsigned int line_number)
{

	stack_t *satck_temp2 = NULL;
	stack_t *stack_temp1 = NULL;
	(void)line_number;

	if (*stack == NULL || ((*stack)->next == NULL))
		return;
	stack_temp1 = *stack;
	while (stack_temp1->next != NULL)
		stack_temp1 = stack_temp1->next;
	satck_temp2 = stack_temp1->prev;
	satck_temp2->next = NULL;
	stack_temp1->prev = NULL;
	stack_temp1->next = *stack;
	(*stack)->prev = stack_temp1;
	*stack = stack_temp1;
}
/**
 * rotr - rotate
 * @stack: head
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *satck_temp2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;
	satck_temp2 = *stack;
	while (satck_temp2->next != NULL)
		satck_temp2 = satck_temp2->next;
	satck_temp2->next = *stack;
	(*stack)->prev = satck_temp2;
	satck_temp2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = satck_temp2;
	(*stack)->prev = NULL;
}
