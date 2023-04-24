#include "holberton.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formatted string.
 *
 * @format: A string containing all characters.
 * @func_list: A list of functions.
 * @arg_list: A list of all arguments.
 *
 * Return: A total of the characters printed.
 */

int parser(const char *format, conver_t func_list[], va_list arg_list)
{
	int m, n, rVal, print_chars;

	print_chars = 0;
	for (m = 0; format[m] != '\0'; m++)
	{
		if (format[m] == '%')
		{

			for (n = 0; func_list[j].sym != NULL; n++)
			{
				if (format[m + 1] == func_list[j].sym[0])
				{
					rVal = func_list[n].f(arg_list);
					if (rVal == -1)
						return (-1);
					print_chars += rVal;
					break;
				}
			}
			if (func_list[j].sym == NULL && format[m + 1] != ' ')
			{
				if (format[m + 1] != '\0')
				{
					write_char(format[m]);
					write_char(format[m + 1]);
					print_chars = print_chars + 2;
				}
				else
					return (-1);
			}
			m = m + 1;
		}
		else
		{
			write_char(format[m]);
			print_chars++;
		}
	}
	return (print_chars);
}