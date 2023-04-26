#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 *
 * @frmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 && 2
 */
int handle_print(const char *frmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	frmt_t frmt_types[] = {
		{'c', display_char}, {'s', display_string}, {'%', display_percent},
		{'i', display_int}, {'d', display_int}, {'b', display_binary},
		{'u', display_unsigned_int}, {'o', display_octa}, {'x', display_hexadecimal},
		{'X', display_hexa_upper}, {'p', display_pointer}, {'S', display_unprintable},
		{'r', display_reverse}, {'R', display_rot13string}, {'\0', NULL}
	};
	for (i = 0; frmt_types[i].frmt != '\0'; i++)
		if (frmt[*ind] == frmt_types[i].frmt)
			return (frmt_types[i].fnc(list, buffer, flags, width, precision, size));

	if (frmt_types[i].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &frmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}