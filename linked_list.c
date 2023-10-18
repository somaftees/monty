#include "monty.h"

/**
 * create_node_stackfirst - create a node
 * @stack: A pointer to top/buttom
 * @n: value
 * Return: the node
 */
stack_t *create_node_stackfirst(stack_t **stack, int n)
{
	stack_t *new_node;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		stderr_malloc();
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	return (new_node);
}

/**
 * create_node_stackend - create a node
 * @stack: A pointer
 * @n: value
 * Return: the node
 */
stack_t *create_node_stackend(stack_t **stack, int n)
{
	stack_t *new_node;
	stack_t *stack_temp;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		stderr_malloc();
	stack_temp = *stack;
	while (stack_temp->next != NULL)
		stack_temp = stack_temp->next;
	stack_temp->next = new_node;
	new_node->n = n;
	new_node->prev = stack_temp;
	new_node->next = NULL;
	return (new_node);
}
/**
 * add_dnodeint - adds a node to stack
 * @head: pointer
 * @n:integer
 * Return: the pointer
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *newnode = NULL;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	newnode->n = n;
	(*head)->prev = newnode;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}
