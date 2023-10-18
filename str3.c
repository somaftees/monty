#include "monty.h"

/**
 * get_int - get char
 * @num: number
 * Return: char pointer
 */

char *get_int(int num)
{
	long num_value = 0;
	unsigned int tmp_value;
	int len_val = 0;
	char *result_val;

	tmp_value = abs_m(num);
	len_val = len_buff_uint(tmp_value, 10);

	if (num < 0 || num_value < 0)
		len_val++;
	result_val = malloc(len_val + 1);
	if (!result_val)
		return (NULL);

	full_buff(tmp_value, 10, result_val, len_val);
	if (num < 0 || num_value < 0)
		result_val[0] = '-';

	return (result_val);
}
/**
 * abs_m - abs
 * @i: integer
 * Return: unsigned
 */
unsigned int abs_m(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
/**
 * len_buff_uint - length of buff
 * @num: number to get
 * @base: base of number
 * Return: int
 */
int len_buff_uint(unsigned int num, unsigned int base)
{
	int len_val = 1;

	while (num > base - 1)
	{
		len_val++;
		num /= base;
	}
	return (len_val);
}
/**
 * full_buff - complete
 * @num: number
 * @base: b number
 * @buff: buffer
 * @buff_size: size
 * Return: void.
 */
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int compare_val, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		compare_val = num % base;
		if (compare_val > 9)
			buff[i] = compare_val + 87;
		else
			buff[i] = compare_val + '0';
		num /= base;
		i--;
	}
}

/**
 * _isdigit - Entry point
* Return: if is digit  or not, return 1 else 0
 */
int _isdigit(void)
{
	int counter = 0;

	if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
		counter++;
	while (globalvar.token2[counter])
	{

		if (isdigit(globalvar.token2[counter]) == 0)
			return (0);
		counter++;
	}
	return (1);
}
