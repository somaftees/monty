#include "monty.h"

/**
 * main - entry point.
 * @argc: count of argument.
 * @argv: pointer.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */

int main(int argc, char **argv)
{
	globales_t globalvar = {NULL, NULL, NULL};
	char *token_type = NULL;
	size_t buf_line_s = 0;
	int line_number = 0, flag = 0, flag2 = 0;
	ssize_t size_of_l;
	stack_t *stack = NULL;

	if (argc != 2)
		stderr_usage();
	globalvar.fd = fopen(argv[1], "r");
	if (globalvar.fd == NULL)
		stderr_fopen(argv[1]);
	size_of_l = getline(&globalvar.line_buf, &buf_line_s, globalvar.fd);
	if (globalvar.line_buf[0] == '#')
		size_of_l = getline(&globalvar.line_buf, &buf_line_s, globalvar.fd);
	while (size_of_l >= 0)
	{flag = 0;
		flag2 = 0;
		line_number++;
		token_type = strtok(globalvar.line_buf, DELIM);
		globalvar.token2 = strtok(NULL, DELIM);
		if (token_type == NULL)
		{flag2 = 1;
			nop(&stack, line_number); }
		if (flag2 == 0)
		{
			if (token_type[0] == '#')
			{
				size_of_l = getline(&globalvar.line_buf,
						    &buf_line_s, globalvar.fd);
				flag = 1; }}
		if (flag == 0)
		{get_builtin(token_type, &stack, line_number);
			size_of_l = getline(&globalvar.line_buf, &buf_line_s,
					    globalvar.fd); }}
	free_dlistint(stack);
	free(globalvar.line_buf);
	globalvar.line_buf = NULL;
	fclose(globalvar.fd);
	return (EXIT_SUCCESS);
}
