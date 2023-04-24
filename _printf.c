#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: string with all characters
 *
 * Return: prin chars
 */
int _printf(const char *format, ...)
{
	int print_chars;
	convert_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"u", unsigned_int},
		{"%", print_percentage},
		{"b", print_binary},
		{"r", print_reversed},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_hex},
		{"R", rot13},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	print_chars = parser(format, f_list, arg_list);
	va_end(arg_list);

	return (print_chars);
}
