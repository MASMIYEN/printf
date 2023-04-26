#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 *
 * @format: Formatted string to print the arguments
 * @i: List of arguments to print.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int jeff_i = *i + 1;
	int precision = -1;

	if (format[jeff_i] != '.')
		return (precision);

	precision = 0;

	for (jeff_i += 1; format[jeff_i] != '\0'; jeff_i++)
	{
		if (is_digit(format[jeff_i]))
		{
			precision *= 10;
			precision += format[jeff_i] - '0';
		}
		else if (format[jeff_i] == '*')
		{
			jeff_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = jeff_i - 1;

	return (precision);
}