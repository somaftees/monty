#include "monty.h"

/**
 * main - entry point.
 * @argc: int.
 * @argv: int.
 * Return: 0 or -1.
 */

int main(int argc, char *argv[])
{
	FILE *x;
	stack_t *s = NULL;
	char *l = NULL;
	char *oc;
	char *n;
	unsigned int ln;
	size_t length = 0;
	ssize_t r;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	x = fopen(argv[1], "r");
	if (x == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	ln = 0;
	while ((r = getline(&l, &length, x)) != -1)
	{
		ln;
		oc = strtok(l, DELIMITERS);
		if (oc == NULL || strncmp(oc, "#", 1) == 0)
			continue;
		if (strcmp(oc, "push") == 0)
		{
			n = strtok(NULL, DELIMITERS);
			push(&s, ln, n);
		}
		else
			opcode_struct(oc, &s, ln);
	}

	free_all(s, l, x);
	return (EXIT_SUCCESS);
}
