#include "main.h"

/**
 * find_size - Calculates the size to cast the argument
 *
 * @format: Formatted string to print the arguments
 * @i: List of arguments to print.
 *
 * Return: Precision.
 */
int find_size(const char *format, int *i)
{
	int jeff_i = *i + 1;
	int size = 0;

	if (format[jeff_i] == 'l')
		size = S_LONG;
	else if (format[jeff_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = jeff_i - 1;
	else
		*i = jeff_i;

	return (size);
}
