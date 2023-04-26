#include "main.h"

/**
 * find_width - Calculates the width for printing
 *
 * @format: Formatted string to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int find_width(const char *format, int *i, va_list list)
{
	int jeff_i;
	int width = 0;

	for (jeff_i = *i + 1; format[jeff_i] != '\0'; jeff_i++)
	{
		if (is_digit(format[jeff_i]))
		{
			width *= 10;
			width += format[jeff_i] - '0';
		}
		else if (format[jeff_i] == '*')
		{
			jeff_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = jeff_i - 1;

	return (width);
}