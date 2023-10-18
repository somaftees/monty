#include "monty.h"

/**
 * array_len - calculates  array
 * Return: Lenght
 */
unsigned int array_len(void)
{
	unsigned int t_lenght = 0;

	while (globalvar.token2[t_lenght])
		t_lenght++;
	return (t_lenght);
}
/**
 * tokerr - makes the last
 * @error_status: type int
 */
void tokerr(int error_status)
{
	int t_lenght = 0, i = 0;
	char *exit_type = NULL;
	char *new_t = NULL;

	t_lenght = array_len();
	new_t = malloc(sizeof(char *) * (t_lenght + 2));
	if (!globalvar.token2)
	{
		stderr_malloc();
		return;
	}
	while (i < t_lenght)
	{
		new_t[i] = globalvar.token2[i];
		i++;
	}
	exit_type = get_int(error_status);
	if (!exit_type)
	{
		free(globalvar.token2);
		stderr_malloc();
		return;
	}
	free(globalvar.token2);
	globalvar.token2 = new_t;
}
