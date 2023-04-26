#include "main.h"

void printf_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 *
 * @format: format.
 *
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				printf_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			printf_buffer(buffer, &buff_ind);
			flags = find_flags(format, &i);
			width = find_width(format, &i, list);
			precision = find_precision(format, &i, list);
			size = find_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	printf_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * printf_buffer - Prints the contents of the buffer
 *
 * @buffer: Array of chars
 *
 * @buff_ind: Index to add next char 'the length'.
 */
void printf_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}